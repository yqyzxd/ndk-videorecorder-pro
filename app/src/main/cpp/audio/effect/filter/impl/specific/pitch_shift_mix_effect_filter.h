//
// Created by wind on 2023/7/13.
//

#ifndef NDK_VIDEORECORDER_PRO_PITCH_SHIFT_MIX_EFFECT_FILTER_H
#define NDK_VIDEORECORDER_PRO_PITCH_SHIFT_MIX_EFFECT_FILTER_H


#include "mix_effect_filter.h"
#include "../../../../../utils/macro.h"

//声音变调
class PitchShiftMixEffectFilter : public MixEffectFilter{
private:
    short* mAccompanyBufQueue;
    short* mVocalBufQueue;
    int mVocalBufCursor;
    int mAccompanyBufCursor;
    int mBufQueueSize;

    int mAudioSampleRate;
    int mChannels;


public:
    PitchShiftMixEffectFilter();
    ~PitchShiftMixEffectFilter();

    int init(AudioEffect* audioEffect);
    int filter(AudioRequest* request,AudioResponse* response);
    void dealloc();

};


#endif //NDK_VIDEORECORDER_PRO_PITCH_SHIFT_MIX_EFFECT_FILTER_H
