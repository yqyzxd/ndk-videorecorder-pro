//
// Created by wind on 2023/7/18.
//

#ifndef NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_BUILDER_H
#define NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_BUILDER_H


#include <jni.h>
#include "audio_effect.h"

class AudioEffectBuilder {
protected:
    void setCompressorFilterParam(JNIEnv* env,jobject compressorParam,SOXFilterChainParam* filterChainParam);
    void setReverbFilterParam(JNIEnv* env,jobject reverbParam,SOXFilterChainParam* filterChainParam);
    void setEqualizerFilterParam(JNIEnv* env,jobject equalizerParam,SOXFilterChainParam* filterChainParam);

    virtual AudioEffect* generateAudioEffect(JNIEnv* env,jobject audioEffect,AudioInfo* audioInfo,
                                             std::list<int>* vocalEffectFilters,
                                             std::list<int>* accompanyEffectFilters,
                                             std::list<int>* mixPostEffectFilters,
                                             float accompanyVolume,
                                             float audioVolume,
                                             SOXFilterChainParam* filterChainParam,
                                             float outputGainParam);

    AudioInfo* getAudioInfo(JNIEnv* env,jobject audioInfo);
public:
    AudioEffectBuilder();
    ~AudioEffectBuilder();

    AudioEffect* buildAudioEffect(JNIEnv* env,jobject audioEffect);
};


#endif //NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_BUILDER_H
