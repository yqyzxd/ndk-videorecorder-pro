//
// Created by wind on 2023/7/11.
//

#ifndef NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_POST_PROCESSOR_H
#define NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_POST_PROCESSOR_H


#include "../audio_effect_processor.h"
#include "../../filter/audio_effect_filter_chain.h"
#include "../../filter/impl/specific/mix_effect_filter.h"


class AudioEffectPostProcessor : public AudioEffectProcessor{
protected:
    //人声处理
    AudioEffectFilterChain* mVocalEffectFilterChain;
    //伴奏处理
    AudioEffectFilterChain* mAccompanyEffectFilterChain;
    //人声和伴奏合并后处理
    AudioEffectFilterChain* mMixPostEffectFilterChain;
    //合并人声和伴奏
    MixEffectFilter* mMixEffectFilter;


    bool mAudioEffectChanged;
    AudioEffect* mAudioEffect;

    void detectRebuildFilterChain();
    virtual void initFilterChains();
    virtual void deallocFilterChains();

    bool isAccompanyPitchShift(AudioEffect* audioEffect);
    bool isRobotAudioEffectFilter(AudioEffect* audioEffect);

public:
    AudioEffectPostProcessor();
    ~AudioEffectPostProcessor();

    virtual void init(AudioEffect *audioEffect);
    virtual AudioResponse* process(short* vocalBuf,int vocalBufSiz,float position,long frameSize);
    virtual AudioResponse* processAccompany(short* accompanyBuf,int accompanyBufSize,float position,long frameSize);
    virtual AudioResponse* process(short* vocalBuf,int vocalBufSize,short* accompanyBuf,int accompanyBufSize,int handleSize);

    virtual void setAudioEffect(AudioEffect* audioEffect);
    virtual void resetFilterChains();
    virtual void dealloc();

};


#endif //NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_POST_PROCESSOR_H
