//
// Created by wind on 2023/7/27.
//

#ifndef NDK_VIDEORECORDER_PRO_BASE_VIDEO_EFFECT_H
#define NDK_VIDEORECORDER_PRO_BASE_VIDEO_EFFECT_H

#include "video_effect_def.h"
#include "opengl_video_frame.h"
#include "gles/base_fbo_filter.h"


class BaseVideoEffect : public BaseFboFilter{
public:
    BaseVideoEffect(const char *vertexSource, const char *fragmentSource);
    BaseVideoEffect(): BaseVideoEffect(base_vertex,base_fragment){
        mEffectCallback= nullptr;
    };
    virtual ~BaseVideoEffect();



    void setEffectCallback(EffectCallback* callback);

protected:
    EffectCallback* mEffectCallback;
};


#endif //NDK_VIDEORECORDER_PRO_BASE_VIDEO_EFFECT_H
