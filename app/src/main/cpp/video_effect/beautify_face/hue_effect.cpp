//
// Created by wind on 2023/8/2.
//

#include "hue_effect.h"
#include "../video_effect_params.h"

HueEffect::HueEffect(): BaseVideoEffect(base_vertex,HUE_EFFECT_FRAGMENT_SHADER){

    uHueAdjustLocation= glGetUniformLocation(mProgram,"u_HueAdjust");
}


HueEffect::~HueEffect() noexcept {

}


void HueEffect::inflateLocation(GLuint textureId) {
    BaseVideoEffect::inflateLocation(textureId);
    if (mEffectCallback!= nullptr){
        ParamVal val;
        bool ok=mEffectCallback->getParamValue(std::string(HUE_EFFECT_HUE_ANGLE_CHANGED),val);
        if (ok){
           bool changed=val.u.boolVal;
            if (changed){
                float hueAngle=360;
                val.u.boolVal= false;
                mEffectCallback->setParamValue(std::string(HUE_EFFECT_HUE_ANGLE_CHANGED),val);

                ok=mEffectCallback->getParamValue(std::string(HUE_EFFECT_HUE_ANGLE),val);
                if (ok){
                    hueAngle=val.u.fltVal;
                }

                float hue = 2 * 3.1415926 * hueAngle / 360.0f;
                glUniform1f(uHueAdjustLocation,hue);
            }

        }
    }
}