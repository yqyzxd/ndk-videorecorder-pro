//
// Created by wind on 2023/8/1.
//

#include "smooth_skin_vertical_effect.h"


SmoothSkinVerticalEffect::SmoothSkinVerticalEffect(): BaseVideoEffect(OPTIMIZED_SKIN_VERTICAL_VERTEX_SHADER,OPTIMIZED_SKIN_VERTICAL_FRAG_SHADER){

    uTexelWidthOffsetLocation= glGetUniformLocation(mProgram, "u_TexelWidthOffset");
    uTexelHeightOffsetLocation= glGetUniformLocation(mProgram, "u_TexelHeightOffset");

    uMaskCurveProgressLocation= glGetUniformLocation(mProgram, "u_MaskCurveProgress");
    uSoftLightProgressLocation= glGetUniformLocation(mProgram, "u_SoftLightProgress");
    uCurveProgressLocation= glGetUniformLocation(mProgram, "u_CurveProgress");
    uSaturationRatioLocation= glGetUniformLocation(mProgram, "u_SaturationRatio");

}

SmoothSkinVerticalEffect::~SmoothSkinVerticalEffect() noexcept {}

void SmoothSkinVerticalEffect::inflateLocation(GLuint textureId) {

    glUniform1f(uTexelWidthOffsetLocation, (GLfloat)(getHighpassRadius() / mWidth));
    glUniform1f(uTexelHeightOffsetLocation, 0.0);

    if (mEffectCallback!= nullptr){
        ParamVal val;
        bool ok =mEffectCallback->getParamValue(std::string(SMOOTH_SKIN_EFFECT_PARAM_CHANGED),val);
        if (ok){
            bool changed=val.u.boolVal;
            if (changed){
                val.u.boolVal= false;
                mEffectCallback->setParamValue(std::string(SMOOTH_SKIN_EFFECT_PARAM_CHANGED),val);
                float maskCurveProgress=0.3;
                ok=mEffectCallback->getParamValue(std::string(MASK_CURVE_PROGRESS),val);
                if (ok){
                    maskCurveProgress=val.u.fltVal;
                }
                glUniform1f(uMaskCurveProgressLocation, maskCurveProgress);

                float softLightProgress=1.0;
                ok=mEffectCallback->getParamValue(std::string(SOFT_LIGHT_PROGRESS), val);
                if (ok){
                    softLightProgress=val.u.fltVal;
                }

                glUniform1f(uSoftLightProgressLocation, softLightProgress);

                float curveProgress=48.0;
                ok=mEffectCallback->getParamValue(std::string(S_CURVE_PROGRESS),val);
                if(ok){
                    curveProgress=val.u.fltVal;
                }
                glUniform1f(uCurveProgressLocation,curveProgress);

                float saturationRatio=0.8f;
                ok=mEffectCallback->getParamValue(std::string(SATU_RATIO),val);
                if (ok){
                    saturationRatio=val.u.fltVal;
                }
                glUniform1f(uSaturationRatioLocation,saturationRatio);
            }

        }
    }

}