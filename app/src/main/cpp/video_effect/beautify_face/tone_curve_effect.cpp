//
// Created by wind on 2023/8/2.
//

#include "tone_curve_effect.h"



ToneCurveEffect::ToneCurveEffect(): BaseVideoEffect(base_vertex,TONE_CURVE_EFFECT_FRAGMENT_SHADER){
    //   "uniform sampler2D u_ToneCurveTexture;\n"
    mToneCurveTexture= nullptr;
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
                if (mToneCurveTexture!= nullptr){
                    mToneCurveTexture->dealloc();
                }
                mToneCurveTexture->createTexture();


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
                }

            }
        }
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
        std::vector<PointF*> points=new std::vector<PointF*>();
        //todo tone curve effect
    }
}

short ToneCurveEffect::readShortFromACVBuffer() {
    short highBit=*mACVBuffer << 8;
    mACVBuffer++;
    short lowBit=*mACVBuffer;
    mACVBuffer++;

    return (short)(highBit | lowBit);
}
