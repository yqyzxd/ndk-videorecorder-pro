//
// Created by wind on 2023/7/13.
//

#ifndef NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_LIVE_PROCESSOR_H
#define NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_LIVE_PROCESSOR_H


#include "../post/audio_effect_post_processor.h"

class AudioEffectLiveProcessor : public AudioEffectPostProcessor{
public:
    AudioEffectLiveProcessor();
    ~AudioEffectLiveProcessor();

    virtual AudioResponse* process(short* vocalBuf,int vocalBufSize,short* accompanyBuf,int accompanyBufSize,int handleSize);

    virtual void initFilterChains();
    virtual void deallocFilterChains();

};


#endif //NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_LIVE_PROCESSOR_H
