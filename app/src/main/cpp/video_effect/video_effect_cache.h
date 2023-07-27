//
// Created by wind on 2023/7/27.
//

#ifndef NDK_VIDEORECORDER_PRO_VIDEO_EFFECT_CACHE_H
#define NDK_VIDEORECORDER_PRO_VIDEO_EFFECT_CACHE_H
#include "base_video_effect.h"
#include <map>
using namespace  std;
class VideoEffectCache {

private:
    map<string,BaseVideoEffect*> mEffectCache;

public:
    VideoEffectCache();
    ~VideoEffectCache();

    BaseVideoEffect* getVideoEffect(string effectName);
};


#endif //NDK_VIDEORECORDER_PRO_VIDEO_EFFECT_CACHE_H
