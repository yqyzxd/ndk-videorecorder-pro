//
// Created by wind on 2023/7/11.
//

#ifndef NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_FILTER_H
#define NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_FILTER_H


#include "../audio_effect.h"
#include "../processor/audio_request.h"
#include "../processor/audio_response.h"

class AudioEffectFilter {
public:
    virtual int init(AudioEffect* audioEffect)=0;
    virtual int filter(AudioRequest* request,AudioResponse* response)=0;
    virtual void dealloc()=0;
};


#endif //NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_FILTER_H
