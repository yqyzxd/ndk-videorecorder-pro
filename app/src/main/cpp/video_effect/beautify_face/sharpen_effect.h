//
// Created by wind on 2023/8/2.
//

#ifndef NDK_VIDEORECORDER_PRO_SHARPEN_EFFECT_H
#define NDK_VIDEORECORDER_PRO_SHARPEN_EFFECT_H

#include "../base_video_effect.h"
#include "../video_effect_params.h"
using namespace std;
static char* SHARPEN_EFFECT_VERTEX_SHADER =
        "                                                                                           \n"
        "attribute vec4 a_Position;                                                                   \n"
        "attribute vec4 a_Coordinate;                                                                   \n"
        "                                                                                           \n"
        "uniform float u_ImageWidthFactor;                                                            \n"
        "uniform float u_ImageHeightFactor;                                                           \n"
        "uniform float u_Sharpness;                                                                   \n"
        "                                                                                           \n"
        "varying vec2 v_TextureCoordinate;                                                            \n"
        "varying vec2 v_LeftTextureCoordinate;                                                        \n"
        "varying vec2 v_RightTextureCoordinate;                                                       \n"
        "varying vec2 v_TopTextureCoordinate;                                                         \n"
        "varying vec2 v_BottomTextureCoordinate;                                                      \n"
        "                                                                                           \n"
        "varying float v_CenterMultiplier;                                                            \n"
        "varying float v_EdgeMultiplier;                                                              \n"
        "                                                                                           \n"
        "void main()                                                                                \n"
        "{                                                                                          \n"
        "    gl_Position = a_Position;                                                                \n"
        "                                                                                           \n"
        "    vec2 widthStep = vec2(u_ImageWidthFactor, 0.0);                                          \n"
        "    vec2 heightStep = vec2(0.0, u_ImageHeightFactor);                                        \n"
        "                                                                                           \n"
        "    v_TextureCoordinate = a_Coordinate.xy;                                                       \n"
        "    v_LeftTextureCoordinate = a_Coordinate.xy - widthStep;                                       \n"
        "    v_RightTextureCoordinate = a_Coordinate.xy + widthStep;                                      \n"
        "    v_TopTextureCoordinate = a_Coordinate.xy + heightStep;                                       \n"
        "    v_BottomTextureCoordinate = a_Coordinate.xy - heightStep;                                    \n"
        "                                                                                           \n"
        "    v_CenterMultiplier = 1.0 + 4.0 * u_Sharpness;                                              \n"
        "    v_EdgeMultiplier = u_Sharpness;                                                            \n"
        "}                                                                                          \n";

/**
 *
 * 锐化的Effect
 *
 * **/
static char* SHARPEN_EFFECT_FRAGMENT_SHADER =
        "precision highp float;                                                                                    \n"
        "                                                                                                          \n"
        "varying highp vec2 v_TextureCoordinate;                                                                     \n"
        "varying highp vec2 v_LeftTextureCoordinate;                                                                 \n"
        "varying highp vec2 v_RightTextureCoordinate;                                                                \n"
        "varying highp vec2 v_TopTextureCoordinate;                                                                  \n"
        "varying highp vec2 v_BottomTextureCoordinate;                                                               \n"
        "                                                                                                          \n"
        "varying highp float v_CenterMultiplier;                                                                     \n"
        "varying highp float v_EdgeMultiplier;                                                                       \n"
        "                                                                                                          \n"
        "uniform sampler2D u_Texture;                                                                          \n"
        "                                                                                                          \n"
        "void main()                                                                                               \n"
        "{                                                                                                         \n"
        "   mediump vec3 textureColor = texture2D(u_Texture, v_TextureCoordinate).rgb;                       \n"
        "   mediump vec3 leftTextureColor = texture2D(u_Texture, v_LeftTextureCoordinate).rgb;               \n"
        "    mediump vec3 rightTextureColor = texture2D(u_Texture, v_RightTextureCoordinate).rgb;            \n"
        "    mediump vec3 topTextureColor = texture2D(u_Texture, v_TopTextureCoordinate).rgb;                \n"
        "    mediump vec3 bottomTextureColor = texture2D(u_Texture, v_BottomTextureCoordinate).rgb;          \n"
        "                                                                                                          \n"
        "    gl_FragColor = vec4((textureColor * v_CenterMultiplier - (leftTextureColor * v_EdgeMultiplier + rightTextureColor * v_EdgeMultiplier + topTextureColor * v_EdgeMultiplier + bottomTextureColor * v_EdgeMultiplier)), texture2D(u_Texture, v_BottomTextureCoordinate).w);\n"
        "}                                                                                                         \n";


class SharpenEffect:public BaseVideoEffect {
public:
    SharpenEffect();
    ~SharpenEffect();

    void inflateLocation(GLuint textureId) override;

private:
    GLint uImageWidthFactorLocation;
    GLint uImageHeightFactorLocation;
    GLint uSharpnessLocation;
};


#endif //NDK_VIDEORECORDER_PRO_SHARPEN_EFFECT_H
