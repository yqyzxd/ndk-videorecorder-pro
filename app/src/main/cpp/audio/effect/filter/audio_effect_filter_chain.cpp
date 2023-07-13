//
// Created by wind on 2023/7/11.
//

#include "audio_effect_filter_chain.h"
#include "audio_effect_filter_factory.h"

AudioEffectFilterChain::AudioEffectFilterChain() {
    mFilters= nullptr;
}
AudioEffectFilterChain::~AudioEffectFilterChain() {}

int AudioEffectFilterChain::init(AudioEffect *audioEffect, std::list<int> *effectFilters) {
    mFilters=new std::list<AudioEffectFilter*>();
    if (effectFilters!= nullptr && effectFilters->size()>0){
        std::list<int>::iterator iter=effectFilters->begin();
        for (; iter!=effectFilters->end() ; ++iter) {
            int effectFilterType=*iter;
            AudioEffectFilter* filter=AudioEffectFilterFactory::GetInstance()->buildFilter(
                    (EffectFilterType)effectFilterType);
            if (filter!= nullptr){
                if (filter->init(audioEffect)>=0){
                    mFilters->push_back(filter);
                }
            }
        }
    }
}

int AudioEffectFilterChain::filter(AudioRequest *request, AudioResponse *response) {

    std::list<AudioEffectFilter*>::iterator  iter=mFilters->begin();
    for(;iter!=mFilters->end();++iter){
        AudioEffectFilter* filter=*iter;
        filter->filter(request,response);

    }
}

void AudioEffectFilterChain::dealloc() {
   std::list<AudioEffectFilter*>::iterator iter=mFilters->begin();
    for (; iter!=mFilters->end() ; ++iter) {
        AudioEffectFilter* filter=*iter;
        filter->dealloc();
        delete filter;
    }
    mFilters->clear();
    delete mFilters;
}