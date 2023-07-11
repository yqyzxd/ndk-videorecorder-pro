//
// Created by wind on 2023/7/10.
//

#include "audio_effect_context.h"


AudioEffectContext::AudioEffectContext() {
    mResponse=new std::map<std::string,void*>();
}

AudioEffectContext::~AudioEffectContext() {
    std::map<std::string,void*>::iterator iter=mResponse->begin();
    for (; iter!=mResponse->end(); ++iter) {
        mResponse->erase(iter->first);
        delete iter->second;
    }
    delete mResponse;
    mResponse= nullptr;
}
AudioEffectContext *AudioEffectContext::instance=new AudioEffectContext();

AudioEffectContext *AudioEffectContext::GetInstance() {
    return instance;
}

void AudioEffectContext::init() {
    //在调用sox_quit前不可重复调用 sox_init
    sox_init();
}

void AudioEffectContext::dealloc() {
    sox_quit();
}

void AudioEffectContext::copy(std::map<std::string, void *> *src) {
    if (src!= nullptr){
        std::map<std::string,void*>::iterator iter=src->begin();
        for (; iter!=src->end(); ++iter) {
            std::string key=iter->first;
            mResponse->erase(key);
            mResponse->insert(std::pair<std::string,void*>(key,iter->second));
        }
    }
}