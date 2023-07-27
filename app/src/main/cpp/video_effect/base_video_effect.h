//
// Created by wind on 2023/7/27.
//

#ifndef NDK_VIDEORECORDER_PRO_BASE_VIDEO_EFFECT_H
#define NDK_VIDEORECORDER_PRO_BASE_VIDEO_EFFECT_H

#include "video_effect_def.h"
#include "opengl_video_frame.h"
class BaseVideoEffect {
public:
    BaseVideoEffect();
    virtual ~BaseVideoEffect();

    virtual bool init();
    virtual void renderEffect(OpenGLVideoFrame* inputFrame,OpenGLVideoFrame outputFrame,EffectCallback* filterCallback,GLfloat* vertexCoords, GLfloat* textureCoords);
    virtual void renderEffect(OpenGLVideoFrame* inputFrame,OpenGLVideoFrame outputFrame,EffectCallback* filterCallback);
    virtual void draw();
    virtual void bindTexture(int texId);
    virtual void destroy();
    virtual void buildParamDefaultValue();

protected:
    char* mVertexShader;
    char* mFragmentShader;

    bool mInitialized;

};


#endif //NDK_VIDEORECORDER_PRO_BASE_VIDEO_EFFECT_H
