//
// Created by wind on 2023/8/1.
//

#ifndef NDK_VIDEORECORDER_PRO_SMOOTH_SKIN_HORIZONTAL_EFFECT_H
#define NDK_VIDEORECORDER_PRO_SMOOTH_SKIN_HORIZONTAL_EFFECT_H


#include "../base_video_effect.h"

static char *OPTIMIZED_SKIN_HORIZONTAL_VERTEX_SHADER =
        "attribute vec4 a_Position;    			   												\n"
        "attribute vec2 a_Coordinate;   	   															\n"
        "uniform float u_TexelWidthOffset;	   														\n"
        "uniform float u_TexelHeightOffset;	   													\n"
        "const int GAUSSIAN_SAMPLES = 9;	   														\n"
        "varying vec2 v_Coordinate;															\n"
        "varying vec2 v_BlurCoordinates[GAUSSIAN_SAMPLES];											\n"
        "																						\n"
        "void main(void)               															\n"
        "{                            															\n"
        "   gl_Position = position;  															\n"
        "   v_Coordinate = a_Coordinate.xy;														\n"
        "   							  															\n"
        "   // Calculate the positions for the blur												\n"
        "   int multiplier = 0;																	\n"
        "   vec2 blurStep;																		\n"
        "   vec2 singleStepOffset = vec2(u_TexelWidthOffset, u_TexelHeightOffset);				\n"
        "   for (int i = 0; i < GAUSSIAN_SAMPLES; i++)											\n"
        "   {																					\n"
        "   		multiplier = (i - ((GAUSSIAN_SAMPLES - 1) / 2));									\n"
        "   		blurStep = float(multiplier) * singleStepOffset;									\n"
        "   		v_BlurCoordinates[i] = a_Coordinate.xy + blurStep;										\n"
        "   }																					\n"
        "}                            															\n";


static char *OPTIMIZED_SKIN_HORIZONTAL_FRAG_SHADER =
        "precision lowp float;																		\n"
        "uniform sampler2D u_Texture;															\n"
        "const lowp int GAUSSIAN_SAMPLES = 9;														\n"
        "varying vec2 v_Coordinate;																\n"
        "varying vec2 v_BlurCoordinates[GAUSSIAN_SAMPLES];												\n"
        "																							\n"
        "void main()																					\n"
        "{																							\n"
        "	lowp float sum = 0.0;																\n"
        "   lowp vec4 fragColor=texture2D(u_Texture,v_Coordinate);							\n"
        "																							\n"


        "    sum += texture2D(u_Texture, v_Coordinate[0]).g * 0.0085;              \n"
        "    sum += texture2D(u_Texture, v_Coordinate[1]).g * 0.0382;              \n"
        "    sum += texture2D(u_Texture, v_Coordinate[2]).g * 0.1114;              \n"
        "    sum += texture2D(u_Texture, v_Coordinate[3]).g * 0.2113;              \n"
        "    sum += texture2D(u_Texture, v_Coordinate[4]).g * 0.2612;              \n"
        "    sum += texture2D(u_Texture, v_Coordinate[5]).g * 0.2113;              \n"
        "    sum += texture2D(u_Texture, v_Coordinate[6]).g * 0.1114;              \n"
        "    sum += texture2D(u_Texture, v_Coordinate[7]).g * 0.0382;              \n"
        "    sum += texture2D(u_Texture, v_Coordinate[8]).g * 0.0085;              \n"



        "	gl_FragColor = vec4(fragColor.rgb, sum);									\n"
        "}																							\n";


class SmoothSkinHorizontalEffect : public BaseVideoEffect {
public:
    SmoothSkinHorizontalEffect();
    virtual ~SmoothSkinHorizontalEffect();

    /**填充AttributeLocation，UniformLocation等*/
    virtual void inflateLocation(GLuint textureId);

private:
    GLint uTexelWidthOffsetLocation;
    GLint uTexelHeightOffsetLocation;


    float getHighpassRadius() {
#ifdef __ANDROID__
            return 2.0f;
#elif defined(__APPLE__)
            return 2.5f;
#endif
    }
};


#endif //NDK_VIDEORECORDER_PRO_SMOOTH_SKIN_HORIZONTAL_EFFECT_H
