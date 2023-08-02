//
// Created by wind on 2023/7/28.
//

#ifndef NDK_VIDEORECORDER_PRO_SATURATION_EFFECT_H
#define NDK_VIDEORECORDER_PRO_SATURATION_EFFECT_H

#include "../base_video_effect.h"

/** 饱和度调节(0.0-2.0 默认效果1.0) **/
static char *SATURATION_EFFECT_FRAGMENT_SHADER = SHADER_STRING(
        precision highp float;
        varying highp vec2 v_Coordinate;
        uniform sampler2D u_Texture;
        uniform lowp float u_Saturation;
        // Values from "Graphics Shaders: Theory and Practice" by Bailey and Cunningham
        const mediump vec3 luminanceWeighting = vec3(0.2125, 0.7154, 0.0721);

        void main()
        {
                lowp vec4 textureColor = texture2D(u_Texture, v_Coordinate);
                lowp float luminance = dot(textureColor.rgb, luminanceWeighting);
                lowp vec3 greyScaleColor = vec3(luminance);
                gl_FragColor = vec4(mix(greyScaleColor, textureColor.rgb, u_Saturation), textureColor.w);
        }
);



class SaturationEffect : public BaseVideoEffect{

public:
    SaturationEffect();
    ~SaturationEffect();

    void inflateLocation(GLuint textureId) override;
private:
    GLuint uSaturationLocation;

};


#endif //NDK_VIDEORECORDER_PRO_SATURATION_EFFECT_H
