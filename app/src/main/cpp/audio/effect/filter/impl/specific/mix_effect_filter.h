//
// Created by wind on 2023/7/13.
//

#ifndef NDK_VIDEORECORDER_PRO_MIX_EFFECT_FILTER_H
#define NDK_VIDEORECORDER_PRO_MIX_EFFECT_FILTER_H


#include "../../../audio_effect.h"
#include "../../audio_effect_filter.h"

class MixEffectFilter : public AudioEffectFilter{
public:
    MixEffectFilter();
    ~MixEffectFilter();

    virtual int init(AudioEffect* audioEffect);
    virtual int filter(AudioRequest* request,AudioResponse* response);
    virtual void dealloc();
};


#endif //NDK_VIDEORECORDER_PRO_MIX_EFFECT_FILTER_H
