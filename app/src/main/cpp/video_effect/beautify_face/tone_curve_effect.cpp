//
// Created by wind on 2023/8/2.
//

#include "tone_curve_effect.h"



ToneCurveEffect::ToneCurveEffect(): BaseVideoEffect(base_vertex,TONE_CURVE_EFFECT_FRAGMENT_SHADER){
    //   "uniform sampler2D u_ToneCurveTexture;\n"
    mToneCurveTextureId= -1;
    uToneCurveTextureLocation=glGetUniformLocation(mProgram,"u_ToneCurveTexture");
}

ToneCurveEffect::~ToneCurveEffect() noexcept {

}

void ToneCurveEffect::inflateLocation(GLuint textureId) {
    if (mEffectCallback!= nullptr){
        ParamVal val;
        bool ok=mEffectCallback->getParamValue(string(TONE_CURVE_FILTER_ACV_BUFFER_CHANGED),val);
        if(ok){
            bool changed=val.u.boolVal;
            if (changed){
                if (mToneCurveTextureId!= -1){
                    glDeleteTextures(1,&mToneCurveTextureId);
                }
                glActiveTexture(GL_TEXTURE3);
                glGenTextures(1, &mToneCurveTextureId);
                glBindTexture(GL_TEXTURE_2D, mToneCurveTextureId);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);


                byte* acvBufferOriginalPtr= nullptr;
                val.u.boolVal= false;
                mEffectCallback->setParamValue(string(TONE_CURVE_FILTER_ACV_BUFFER_CHANGED),val);
                ok = mEffectCallback->getParamValue(string(TONE_CURVE_FILTER_ACV_BUFFER), val);
                if (ok){
                    mACVBuffer=(byte*)val.u.arbitrary;
                    acvBufferOriginalPtr=this->mACVBuffer;
                }

                ok = mEffectCallback->getParamValue(string(TONE_CURVE_FILTER_ACV_BUFFER_SIZE), val);
                if (ok){
                    mACVBufferSize=val.u.intVal;
                }
                if (acvBufferOriginalPtr!= nullptr){
                    fillControlPointsFromACVBuffer();
                    mRgbCompositeCurve=createSplineCurve(mRgbCompositeControlPoints);
                    mRedCurve=createSplineCurve(mRedControlPoints);
                    mGreenCurve=createSplineCurve(mGreenControlPoints);
                    mBlueCurve=createSplineCurve(mBlueControlPoints);


                    delete mRgbCompositeControlPoints;
                    delete mRedControlPoints;
                    delete mGreenControlPoints;
                    delete mBlueControlPoints;

                    updateToneCurveTexture();

                    delete mRgbCompositeCurve;
                    delete mRedCurve;
                    delete mGreenCurve;
                    delete mBlueCurve;

                    delete[] acvBufferOriginalPtr;
                    this->mACVBuffer= nullptr;




                }

            }
        }
    }

    if (mToneCurveTextureId!= -1){
        glActiveTexture(GL_TEXTURE3);
        glBindTexture(GL_TEXTURE_2D,mToneCurveTextureId);
        glUniform1f(uToneCurveTextureLocation,3);
    }
}
bool compare(PointF* src, PointF* target) {
    return (src->x < target->x);
}
std::vector<float> *ToneCurveEffect::createSplineCurve(std::vector<PointF *> *points) {
    if (points == nullptr || points->empty()){
        return nullptr;
    }

    sort(points->begin(),points->end(),compare);

    std::vector<PointF*>* convertedPoints=new  std::vector<PointF*>();
    std::vector<PointF*>::iterator  iter=points->begin();
    for (; iter!= points->end(); ++iter) {
        PointF* pointF=*iter;
        convertedPoints->push_back(new PointF((int)(pointF->x * 255),(int)(pointF->y* 255));
        delete pointF;
    }

    std::vector<PointF*>* splinePoints= createSplineCurve2(convertedPoints);


}

std::vector<PointF *> *ToneCurveEffect::createSplineCurve2(std::vector<PointF *> *points) {
    std::vector<double>* sdA=createSecondDerivative(points);
    int n =sdA->size();
    if (n<1){
        return nullptr;
    }
    double sd[n];
    for (int i = 0; i < n; ++i) {
        sd[i]=sdA->at(i);
    }
    delete sdA;

    vector<PointF*>* output=new vector<PointF*>();
    for (int i = 0; i < n-1; ++i) {
        PointF* cur=points->at(i);
        PointF* next=points->at(i+1);
        for (int x = cur->x; x < next->x; ++x) {
            double t=(x-cur->x)/(next->x-cur->x);
            double a=1-t;
            double b=t;
            double h=next->x - cur->x;
            double y = a * cur->y + b * next->y + (h * h / 6) * ((a * a * a - a) * sd[i] + (b * b * b - b) * sd[i + 1]);
            if (y>255.0){
                y=255.0;
            } else if (y<0.0){
                y=0.0;
            }
            output->push_back(new PointF(x, (int )round(y)));
        }
    }

    if(output->size() == 255){
        PointF* pointF=points->at(points->size()-1);
        output->push_back(new PointF(pointF->x,pointF->y));
    }
    return output;
}

std::vector<double> *ToneCurveEffect::createSecondDerivative(std::vector<PointF *> *points) {

    int n = points->size();
    if (n <= 1) {
        return NULL;
    }

    double matrix[n][3];
    double result[n];

    matrix[0][1] = 1;
    // What about matrix[0][1] and matrix[0][0]? Assuming 0 for now (Brad L.)
    matrix[0][0] = 0;
    matrix[0][2] = 0;

    for (int i = 1; i < n - 1; i++) {
        PointF* P1 = points->at(i - 1);
        PointF* P2 = points->at(i);
        PointF* P3 = points->at(i + 1);

        matrix[i][0] = (double) (P2->x - P1->x) / 6;
        matrix[i][1] = (double) (P3->x - P1->x) / 3;
        matrix[i][2] = (double) (P3->x - P2->x) / 6;
        result[i] = (double) (P3->y - P2->y) / (P3->x - P2->x) - (double) (P2->y - P1->y) / (P2->x - P1->x);
    }

    // What about result[0] and result[n-1]? Assuming 0 for now (Brad L.)
    result[0] = 0;
    result[n - 1] = 0;

    matrix[n - 1][1] = 1;
    // What about matrix[n-1][0] and matrix[n-1][2]? For now, assuming they are 0 (Brad L.)
    matrix[n - 1][0] = 0;
    matrix[n - 1][2] = 0;

    // solving pass1 (up->down)
    for (int i = 1; i < n; i++) {
        double k = matrix[i][0] / matrix[i - 1][1];
        matrix[i][1] -= k * matrix[i - 1][2];
        matrix[i][0] = 0;
        result[i] -= k * result[i - 1];
    }
    // solving pass2 (down->up)
    for (int i = n - 2; i >= 0; i--) {
        double k = matrix[i][2] / matrix[i + 1][1];
        matrix[i][1] -= k * matrix[i + 1][0];
        matrix[i][2] = 0;
        result[i] -= k * result[i + 1];
    }

    std::vector<double>* output = new std::vector<double>();
    for (int i = 0; i < n; i++) {
        output->push_back(result[i] / matrix[i][1]);
    }
    return output;
}

void ToneCurveEffect::updateToneCurveTexture() {
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D,mToneCurveTextureId);

    if (mRedCurve->size()>=256 &&
            mGreenCurve->size()>=256 &&
                mBlueCurve->size()>=256 &&
                    mRgbCompositeCurve->size() >= 256){
        byte toneCurveByteArray[256*4];
        for (int currentCurveIndex = 0; currentCurveIndex < 256; ++currentCurveIndex) {
            // BGRA for upload to texture
            toneCurveByteArray[currentCurveIndex * 4] = (byte) ((int) std::min(std::max(currentCurveIndex + mRedCurve->at(currentCurveIndex) + mRgbCompositeCurve->at(currentCurveIndex), 0.0f, compareFloat), 255.0f, compareFloat) & 0xff);
            toneCurveByteArray[currentCurveIndex * 4 + 1] = (byte) ((int) std::min(std::max(currentCurveIndex + mGreenCurve->at(currentCurveIndex) + mRgbCompositeCurve->at(currentCurveIndex), 0.0f, compareFloat), 255.0f, compareFloat) & 0xff);
            toneCurveByteArray[currentCurveIndex * 4 + 2] = (byte) ((int) std::min(std::max(currentCurveIndex + mBlueCurve->at(currentCurveIndex) + mRgbCompositeCurve->at(currentCurveIndex), 0.0f, compareFloat), 255.0f, compareFloat) & 0xff);
            toneCurveByteArray[currentCurveIndex * 4 + 3] = (byte) (255 & 0xff);
        }
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,256/*width*/,1/*height*/,0,GL_RGBA, GL_UNSIGNED_BYTE, toneCurveByteArray);
    }
}
void ToneCurveEffect::fillControlPointsFromACVBuffer() {

    int version=readShortFromACVBuffer();
    int totalCurves=readShortFromACVBuffer();

    float pointRatio=1.0f/255;
    for (int i=0;i<totalCurves;i++){
        if(i>3){
            return;
        }
        short pointCount=readShortFromACVBuffer();
        std::vector<PointF*>* points=new std::vector<PointF*>();
        for (int j = 0; j < pointCount; ++j) {
            short y=readShortFromACVBuffer();
            short x=readShortFromACVBuffer();
            points->push_back(new PointF(x * pointRatio,y * pointRatio));
        }
        if (i == 0 ){
            mRgbCompositeControlPoints=points;
        } else if (i==1){
            mRedControlPoints=points;
        } else if (i==2){
            mGreenControlPoints=points;
        } else if (i==3){
            mBlueControlPoints=points;
        }
    }
}

short ToneCurveEffect::readShortFromACVBuffer() {
    short highBit=*mACVBuffer << 8;
    mACVBuffer++;
    short lowBit=*mACVBuffer;
    mACVBuffer++;

    return (short)(highBit | lowBit);
}
