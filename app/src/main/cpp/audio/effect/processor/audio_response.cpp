//
// Created by wind on 2023/7/10.
//

#include "audio_response.h"

AudioResponse::AudioResponse() {
    mExtraData=new std::map<std::string,void*>();
}

void AudioResponse::put(std::string key,void* value){
    mExtraData->insert(std::pair<std::string,void*>(key,value));
}
void* AudioResponse::get(std::string key){
    std::map<std::string,void*>::iterator iter=mExtraData->find(key);
    if (iter!=mExtraData->end()){
        return iter->second;
    }
    return nullptr;
}

void AudioResponse::dealloc() {
    mExtraData->clear();
}