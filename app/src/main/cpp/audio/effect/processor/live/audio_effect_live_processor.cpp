//
// Created by wind on 2023/7/13.
//

#include "audio_effect_live_processor.h"

AudioEffectLiveProcessor::AudioEffectLiveProcessor() {

}

AudioEffectLiveProcessor::~AudioEffectLiveProcessor() {

}

AudioResponse *
AudioEffectLiveProcessor::process(short *vocalBuf, int vocalBufSize, short *accompanyBuf,
                                  int accompanyBufSize, float position, int frameSize) {

    detectRebuildFilterChain();
    mRequest->init(vocalBuf,vocalBufSize,accompanyBuf,accompanyBufSize,position,frameSize);
    mResponse->dealloc();
    mVocalEffectFilterChain->filter(mRequest,mResponse);

    mMixEffectFilter->filter(mRequest,mResponse);
    //后处理
    mMixPostEffectFilterChain->filter(mRequest,mResponse);
    return mResponse;

}

void AudioEffectLiveProcessor::initFilterChains() {
    mVocalEffectFilterChain->init(mAudioEffect,mAudioEffect->getVocalEffectFilters());
    mMixPostEffectFilterChain->init(mAudioEffect,mAudioEffect->getMixPostEffectFilters());

    mMixEffectFilter=new MixEffectFilter();
    mMixEffectFilter->init(mAudioEffect);
}

void AudioEffectLiveProcessor::deallocFilterChains() {
    mVocalEffectFilterChain->dealloc();
    mMixPostEffectFilterChain->dealloc();
    if (mMixEffectFilter!= nullptr){
        mMixEffectFilter->dealloc();
        delete mMixEffectFilter;
        mMixEffectFilter= nullptr;
    }
}