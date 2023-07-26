//
// Created by wind on 2023/7/11.
//

#include "audio_effect_post_processor.h"
#include "../../filter/impl/specific/pitch_shift_mix_effect_filter.h"
#include "../../filter/audio_effect_filter_factory.h"

AudioEffectPostProcessor::AudioEffectPostProcessor() {
    mRequest=new AudioRequest();
    mResponse=new AudioResponse();
}

AudioEffectPostProcessor::~AudioEffectPostProcessor() {
    delete mRequest;
    delete mResponse;
}

void AudioEffectPostProcessor::init(AudioEffect *audioEffect) {
    AudioEffectProcessor::init(audioEffect);
    this->mAudioEffect=audioEffect;
    mAudioEffectChanged= false;
    mVocalEffectFilterChain=new AudioEffectFilterChain();
    mAccompanyEffectFilterChain=new AudioEffectFilterChain();
    mMixPostEffectFilterChain=new AudioEffectFilterChain();

    this->initFilterChains();
}


AudioResponse *AudioEffectPostProcessor::process(short *vocalBuf, int vocalBufSize, float position,
                                                 long frameSize) {
    detectRebuildFilterChain();
    mRequest->init(vocalBuf,vocalBufSize,position,frameSize);
    mResponse->dealloc();
    mVocalEffectFilterChain->filter(mRequest,mResponse);
    mMixPostEffectFilterChain->filter(mRequest,mResponse);

    return mResponse;

}

AudioResponse *
AudioEffectPostProcessor::process(short *vocalBuf, int vocalBufSize, short *accompanyBuf,
                                  int accompanyBufSize,int handleSize) {
    detectRebuildFilterChain();
    mRequest->init(vocalBuf,vocalBufSize,accompanyBuf,accompanyBufSize);
    mResponse->dealloc();
    mVocalEffectFilterChain->filter(mRequest,mResponse);
    mAccompanyEffectFilterChain->filter(mRequest,mResponse);
    mMixEffectFilter->filter(mRequest,mResponse);
    mMixPostEffectFilterChain->filter(mRequest,mResponse);
    return mResponse;
}

AudioResponse *AudioEffectPostProcessor::processAccompany(short *accompanyBuf, int accompanyBufSize,
                                                          float position, long frameSize) {
    detectRebuildFilterChain();
    mRequest->initAccompany(accompanyBuf,accompanyBufSize,position,frameSize);
    mResponse->dealloc();
    mAccompanyEffectFilterChain->filter(mRequest,mResponse);
    mMixPostEffectFilterChain->filter(mRequest,mResponse);
    return mResponse;
}

void AudioEffectPostProcessor::detectRebuildFilterChain() {
    if (mAudioEffectChanged){
        this->deallocFilterChains();
        this->initFilterChains();
        mAudioEffectChanged= false;
    }
}

void AudioEffectPostProcessor::resetFilterChains() {
    setAudioEffect(mAudioEffect);
}
void AudioEffectPostProcessor::initFilterChains() {
    mVocalEffectFilterChain->init(mAudioEffect,mAudioEffect->getVocalEffectFilters());
    mAccompanyEffectFilterChain->init(mAudioEffect,mAudioEffect->getAccompanyEffectFilters());
    mMixPostEffectFilterChain->init(mAudioEffect,mAudioEffect->getMixPostEffectFilters());

    if (isAccompanyPitchShift(mAudioEffect) || isRobotAudioEffectFilter(mAudioEffect)){
        //需要进行变调
        mMixEffectFilter=new PitchShiftMixEffectFilter();
    } else{
        mMixEffectFilter=new MixEffectFilter();
    }
    mMixEffectFilter->init(mAudioEffect);

}

bool AudioEffectPostProcessor::isAccompanyPitchShift(AudioEffect *audioEffect) {
    if (audioEffect== nullptr){
        return false;
    }
    AudioInfo* audioInfo=audioEffect->getAudioInfo();
    if (audioEffect== nullptr){
        return false;
    }
    return audioInfo->accompanyPitch !=1.0f || audioInfo->pitchShiftLevel!=0;
}

bool AudioEffectPostProcessor::isRobotAudioEffectFilter(AudioEffect *audioEffect) {
    if (audioEffect== nullptr){
        return false;
    }
    std::list<int>* effectFilters= audioEffect->getVocalEffectFilters();
    if (effectFilters== nullptr || effectFilters->size()==0){
        return false;
    }

   std::list<int>::iterator  iter=effectFilters->begin();
    for (;iter!=effectFilters->end();++iter) {
        if (*iter==FilterTypeVocalPitchShift){
            return true;
        }
    }
    return false;
}

void AudioEffectPostProcessor::deallocFilterChains() {
    mVocalEffectFilterChain->dealloc();
    mAccompanyEffectFilterChain->dealloc();
    mMixPostEffectFilterChain->dealloc();

    if (mMixEffectFilter!= nullptr){
        mMixEffectFilter->dealloc();
        delete mMixEffectFilter;
        mMixEffectFilter= nullptr;
    }
}

void AudioEffectPostProcessor::setAudioEffect(AudioEffect *audioEffect) {
    mAudioEffect=audioEffect;
    mAudioEffectChanged= true;
}

void AudioEffectPostProcessor::dealloc() {
    mResponse->dealloc();
    this->deallocFilterChains();
    if (mVocalEffectFilterChain!= nullptr){
        delete mVocalEffectFilterChain;
        mVocalEffectFilterChain = nullptr;
    }
    if (mAccompanyEffectFilterChain!= nullptr){
        delete mAccompanyEffectFilterChain;
        mAccompanyEffectFilterChain = nullptr;
    }

    if (mMixPostEffectFilterChain!= nullptr){
        delete mMixPostEffectFilterChain;
        mMixPostEffectFilterChain = nullptr;
    }
    AudioEffectProcessor::dealloc();
}