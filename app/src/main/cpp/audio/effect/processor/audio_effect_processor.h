//
// Created by wind on 2023/7/10.
//

#ifndef NDK_VIDEORECORDER_AUDIO_EFFECT_PROCESSOR_H
#define NDK_VIDEORECORDER_AUDIO_EFFECT_PROCESSOR_H


#include "audio_request.h"
#include "audio_response.h"
#include "../audio_effect.h"
#include "audio_effect_context.h"

class AudioEffectProcessor {
protected:
    AudioRequest* mRequest;
    AudioResponse* mResponse;

public:
    virtual void init(AudioEffect* audioEffect){
        AudioEffectContext::GetInstance()->init();
    }

    virtual AudioResponse* process(short* vocalBuf,int vocalBufSiz,float position,long frameSize)=0;
    virtual AudioResponse* processAccompany(short* accompanyBuf,int accompanyBufSize,float position,long frameSize)=0;
    virtual AudioResponse* process(short* vocalBuf,int vocalBufSize,short* accompanyBuf,int accompanyBufSize,int handleSize)=0;

    virtual void setAudioEffect(AudioEffect* audioEffect)=0;
    virtual void dealloc(){
        AudioEffectContext::GetInstance()->dealloc();
    }


    AudioResponse* getResponse(){
        return mResponse;
    }
};


#endif //NDK_VIDEORECORDER_AUDIO_EFFECT_PROCESSOR_H
