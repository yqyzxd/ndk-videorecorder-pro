//
// Created by wind on 2023/7/18.
//

#include "audio_effect_builder.h"


AudioEffectBuilder::AudioEffectBuilder() {}
AudioEffectBuilder::~AudioEffectBuilder() {}


AudioEffect *AudioEffectBuilder::buildAudioEffect(JNIEnv *env, jobject audioEffect) {


}

AudioEffect *
AudioEffectBuilder::generateAudioEffect(JNIEnv *env, jobject audioEffect, AudioInfo *audioInfo,
                                        std::list<int> *vocalEffectFilters,
                                        std::list<int> *accompanyEffectFilters,
                                        std::list<int> *mixPostEffectFilters, float accompanyVolume,
                                        float audioVolume, SOXFilterChainParam *filterChainParam,
                                        float outputGainParam) {

}

AudioInfo *AudioEffectBuilder::getAudioInfo(JNIEnv *env, jobject audioInfo) {

}