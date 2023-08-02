//
// Created by wind on 2023/8/2.
//

#include "sharpen_effect.h"


SharpenEffect::SharpenEffect(): BaseVideoEffect(SHARPEN_EFFECT_VERTEX_SHADER,SHARPEN_EFFECT_FRAGMENT_SHADER) {


    uImageWidthFactorLocation = glGetUniformLocation(mProgram, "u_ImageWidthFactor");
    uImageHeightFactorLocation = glGetUniformLocation(mProgram, "u_ImageHeightFactor");
    uSharpnessLocation = glGetUniformLocation(mProgram, "u_Sharpness");
}

SharpenEffect::~SharpenEffect() {

}

void SharpenEffect::inflateLocation(GLuint textureId) {
    if (mEffectCallback!= nullptr){
        ParamVal val;
        bool ok=mEffectCallback->getParamValue(string(SHARPEN_EFFECT_SHARPNESS),val);
        float  sharpness=0.0f;
        if (ok){
          sharpness=val.u.fltVal;
        }
        glUniform1f(uSharpnessLocation,sharpness);


        ok=mEffectCallback->getParamValue(string(IMAGE_EFFECT_GROUP_TEXTURE_WIDTH),val);
        float inputWidth = 720.f;
        if(ok){
            inputWidth=val.u.intVal;
        }

        glUniform1f(uImageWidthFactorLocation,1.0/inputWidth);


        ok=mEffectCallback->getParamValue(string(IMAGE_EFFECT_GROUP_TEXTURE_HEIGHT),val);
        float inputHeight = 1280.f;
        if(ok){
            inputHeight=val.u.intVal;
        }

        glUniform1f(uImageHeightFactorLocation,1.0/inputHeight);

    }

}