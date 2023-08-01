//
// Created by wind on 2023/8/1.
//

#ifndef NDK_VIDEORECORDER_PRO_SMOOTH_SKIN_VERTICAL_EFFECT_H
#define NDK_VIDEORECORDER_PRO_SMOOTH_SKIN_VERTICAL_EFFECT_H


#include "../base_video_effect.h"
#include "../video_effect_params.h"

static char *OPTIMIZED_SKIN_VERTICAL_VERTEX_SHADER =
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
        "   gl_Position = a_Position;  															\n"
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


static char *OPTIMIZED_SKIN_VERTICAL_FRAG_SHADER =
        "precision lowp float;																	\n"
        "uniform sampler2D u_Texture;														\n"
        "const lowp int GAUSSIAN_SAMPLES = 9;													\n"
        "varying vec2 v_Coordinate;															\n"
        "varying vec2 v_BlurCoordinates[GAUSSIAN_SAMPLES];											\n"
        "uniform mediump float u_MaskCurveProgress;                                                     \n"
        "uniform mediump float u_SoftLightProgress;                                                  \n"
        "uniform mediump float u_CurveProgress;                                               \n"
        "uniform mediump float u_SaturationRatio;                                               \n"
        "																						\n"
        "void main()																				\n"
        "{																						\n"
        "	float sum = 0.0;															\n"
        "   lowp vec4 fragColor=texture2D(u_Texture,v_Coordinate);						\n"
        "																						\n"


        "    sum += texture2D(u_Texture, v_BlurCoordinates[0]).a * 0.0085;              \n"
        "    sum += texture2D(u_Texture, v_BlurCoordinates[1]).a * 0.0382;              \n"
        "    sum += texture2D(u_Texture, v_BlurCoordinates[2]).a * 0.1114;              \n"
        "    sum += texture2D(u_Texture, v_BlurCoordinates[3]).a * 0.2113;              \n"
        "    sum += texture2D(u_Texture, v_BlurCoordinates[4]).a * 0.2612;              \n"
        "    sum += texture2D(u_Texture, v_BlurCoordinates[5]).a * 0.2113;              \n"
        "    sum += texture2D(u_Texture, v_BlurCoordinates[6]).a * 0.1114;              \n"
        "    sum += texture2D(u_Texture, v_BlurCoordinates[7]).a * 0.0382;              \n"
        "    sum += texture2D(u_Texture, v_BlurCoordinates[8]).a * 0.0085;              \n"

        "																						\n"
        "   sum = fragColor.g - sum + 0.5; \n"
        //sum 的结果是highpass filter

        //三次强光混合
        "   if (sum <=0.5) \n"
        "   { \n"
        "       sum = 128.0 * sum * sum * sum * sum * sum * sum * sum * sum ; \n"
        "   }\n"
        "   else \n"
        "   { \n"
        "       sum = 1.0 - sum; \n"
        "       sum = 1.0 - 128.0 * sum * sum * sum * sum * sum * sum * sum * sum ; \n"
        "   } \n"
        //蒙版曲线
        "   lowp vec4 fc1 = fragColor; \n"
        "   fc1.rgb = fragColor.rgb * (u_MaskCurveProgress*fragColor.rgb+(1.0*(1.0 - fragColor.rgb))) + fragColor.rgb * (1.0 - u_MaskCurveProgress);  \n"
        "   gl_FragColor = vec4(mix(fc1, fragColor, sum).rgb,1.0);  \n"

        //提亮
        "mediump vec4 overlay = vec4(0.6, 0.6, 0.6, u_SoftLightProgress);     \n"
        "gl_FragColor.rgb = gl_FragColor.rgb * (overlay.a * gl_FragColor.rgb + (2.0 * overlay.rgb * (1.0 - gl_FragColor.rgb ))) + gl_FragColor.rgb * (1.0 - overlay.a);\n"
        //饱和度
        "   float gray = gl_FragColor.r * 0.3 + gl_FragColor.g * 0.59 + gl_FragColor.b * 0.11; \n"
        "   gl_FragColor.rgb = gl_FragColor.rgb * u_SaturationRatio + (1.0 - u_SaturationRatio) * gray; \n"
        //S对比度
        "   gl_FragColor.rgb = u_MaskCurveProgress * gl_FragColor.rgb*(gl_FragColor.rgb+(2.0*gl_FragColor.rgb*(1.0-gl_FragColor.rgb))) + gl_FragColor.rgb*(1.0-u_MaskCurveProgress);  \n"



        "}																						\n";


class SmoothSkinVerticalEffect : public BaseVideoEffect {
public:
    SmoothSkinVerticalEffect();

    ~SmoothSkinVerticalEffect();

    /**填充AttributeLocation，UniformLocation等*/
    virtual void inflateLocation(GLuint textureId);

private:


    GLint uTexelWidthOffsetLocation;
    GLint uTexelHeightOffsetLocation;
    GLint uMaskCurveProgressLocation;
    GLint uSoftLightProgressLocation;
    GLint uCurveProgressLocation;
    GLint uSaturationRatioLocation;


    float getHighpassRadius() {
#ifdef __ANDROID__
        return 2.0f;
#elif defined(__APPLE__)
        return 2.5f;
#endif
    }
};


#endif //NDK_VIDEORECORDER_PRO_SMOOTH_SKIN_VERTICAL_EFFECT_H
