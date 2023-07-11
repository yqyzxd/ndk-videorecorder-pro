//
// Created by wind on 2023/7/10.
//

#include "audio_effect.h"
AudioEffect::AudioEffect() {

}

AudioEffect::AudioEffect(AudioInfo *audioInfo, float accompanyVolume, float audioVolume,
                         SOXFilterChainParam *soxFilterChainParam,
                         std::list<int> *vocalEffectFilters, std::list<int> *accompanyEffectFilters,
                         std::list<int> *mixPostEffectFilters, float outputGain) {
    this->mAudioInfo=audioInfo;
    this->mAccompanyVolume=accompanyVolume;
    this->mAudioVolume=audioVolume;
    this->mSOXFilterChainParam=soxFilterChainParam;
    this->mVocalEffectFilters=vocalEffectFilters;
    this->mAccompanyEffectFilters=accompanyEffectFilters;
    this->mMixPostEffectFilters=mixPostEffectFilters;
    this->mOutputGain=outputGain;
}

AudioEffect::~AudioEffect() {}