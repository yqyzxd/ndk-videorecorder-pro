//
// Created by wind on 2023/7/11.
//

#ifndef NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_FILTER_CHAIN_H
#define NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_FILTER_CHAIN_H
#include <list>
#include "audio_effect_filter.h"

class AudioEffectFilterChain {
private:
    std::list<AudioEffectFilter*>* mFilter;
public:
    AudioEffectFilterChain();
    ~AudioEffectFilterChain();

    int init(AudioEffect* audioEffect, std::list<int>* effectFilters);
    int filter(AudioRequest* request,AudioResponse* response);
    void dealloc();
};


#endif //NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_FILTER_CHAIN_H
