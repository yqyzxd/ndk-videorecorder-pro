//
// Created by wind on 2023/7/10.
//

#ifndef NDK_VIDEORECORDER_AUDIO_EFFECT_H
#define NDK_VIDEORECORDER_AUDIO_EFFECT_H


#include "audio_info.h"
#include "param/sox_filter_chain_param.h"
#include <list>

class AudioEffect {
    AudioInfo* mAudioInfo;
    float mAccompanyVolume;
    float mAudioVolume;

    /**配置文件中读取实现解耦*/
    SOXFilterChainParam* mSOXFilterChainParam;
    std::list<int>* mVocalEffectFilters;
    std::list<int>* mAccompanyEffectFilters;
    std::list<int>* mMixPostEffectFilters;


    //用来计算人声伴奏音量
    float mOutputGain;

public:
    AudioEffect();
    AudioEffect(AudioInfo* audioInfo,float accompanyVolume,float audioVolume,
                SOXFilterChainParam* soxFilterChainParam,std::list<int>* vocalEffectFilters,
                std::list<int>* accompanyEffectFilters,
                std::list<int>* mixPostEffectFilters,
                float outputGain
                );
    ~AudioEffect();


    float getAccompanyVolume(){
        return mAccompanyVolume;
    }
    float getAudioVolume(){
        return mAudioVolume;
    }

    AudioInfo* getAudioInfo(){
        return mAudioInfo;
    }



};


#endif //NDK_VIDEORECORDER_AUDIO_EFFECT_H
