//
// Created by wind on 2023/8/2.
//

#ifndef NDK_VIDEORECORDER_PRO_TONE_CURVE_EFFECT_H
#define NDK_VIDEORECORDER_PRO_TONE_CURVE_EFFECT_H


#include "../base_video_effect.h"
#include "gles/texture.h"
#include "../../utils/types.h"
#include "../video_effect_params.h"
#include <vector>
using namespace std;
/**
 * 色调曲线 可以实现:小清新、优雅、幻彩、日系、枫叶等 效果
 * **/
static char* TONE_CURVE_EFFECT_FRAGMENT_SHADER =
        "precision lowp float;\n"
        "precision lowp sampler2D;\n"
        "varying lowp vec2 v_Coordinate;\n"
        "uniform sampler2D u_Texture;\n"
        "uniform sampler2D u_ToneCurveTexture;\n"
        "void main() {\n"
        "lowp vec4 textureColor = texture2D(u_Texture, v_Coordinate);\n"
        "float redCurveValue = texture2D(u_ToneCurveTexture, vec2(textureColor.r, 0.0)).r;\n"
        "float greenCurveValue = texture2D(u_ToneCurveTexture, vec2(textureColor.g, 0.0)).g;\n"
        "float blueCurveValue = texture2D(u_ToneCurveTexture, vec2(textureColor.b, 0.0)).b;\n"
        "\n"
        "gl_FragColor = vec4(redCurveValue, greenCurveValue, blueCurveValue, textureColor.a);\n"
        "}\n";
typedef struct PointF{
    float x;
    float y;

    bool operator < (PointF* pointF) const{
            return x < pointF->x;
    }
    bool operator > (PointF* pointF) const{
            return x > pointF->x;
    }
    PointF(float x,float y):x(x),y(y){}
} PointF;

class ToneCurveEffect : public BaseVideoEffect{
public:
    ToneCurveEffect();
    ~ToneCurveEffect();

    virtual void inflateLocation(GLuint textureId);

private:
    Texture* mToneCurveTexture;
    GLint uToneCurveTextureLocation;

    byte* mACVBuffer;
    int mACVBufferSize;

    void fillControlPointsFromACVBuffer();

    short readShortFromACVBuffer();
};


#endif //NDK_VIDEORECORDER_PRO_TONE_CURVE_EFFECT_H
