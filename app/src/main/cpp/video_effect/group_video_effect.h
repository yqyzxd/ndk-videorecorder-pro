//
// Created by wind on 2023/7/28.
//

#ifndef NDK_VIDEORECORDER_PRO_GROUP_VIDEO_EFFECT_H
#define NDK_VIDEORECORDER_PRO_GROUP_VIDEO_EFFECT_H


#include "base_video_effect.h"
#include "../libgles/gles/base_filter.h"
#include "../libgles/gles/gl_utils.h"
#include <list>

using namespace std;
class GroupVideoEffect:public BaseVideoEffect{
public:
    GroupVideoEffect();
    virtual ~GroupVideoEffect();
    virtual void onReady(int width, int height);
    virtual GLuint onDrawFrame(GLuint textureId);
    virtual void dealloc();

    void addEffect(BaseVideoEffect* effect);

private:
    list<BaseVideoEffect*>* mEffects;
};


#endif //NDK_VIDEORECORDER_PRO_GROUP_VIDEO_EFFECT_H
