//
// Created by wind on 2023/7/28.
//

#include "saturation_effect.h"
#include "../video_effect_params.h"

SaturationEffect::SaturationEffect():BaseVideoEffect(base_vertex,SATURATION_EFFECT_FRAGMENT_SHADER) {

    //get location
    uSaturationLocation= glGetUniformLocation(mProgram,"u_Texture");
}

SaturationEffect::~SaturationEffect() noexcept {

}

void SaturationEffect::inflateLocation(GLuint textureId) {
    float saturation=1.0f;
    if (mEffectCallback!= nullptr){
        ParamVal val;
        bool suc=mEffectCallback->getParamValue(std::string(SATURATION_SCENE_PARAM_ID_SATURATION),val);
        if (suc){
            saturation=val.u.fltVal;
        }
    }

    glUniform1f(uSaturationLocation,saturation);
}

