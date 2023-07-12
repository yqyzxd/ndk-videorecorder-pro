//
// Created by wind on 2023/7/11.
//

#include "audio_effect_filter_factory.h"


AudioEffectFilterFactory::AudioEffectFilterFactory() {

}

AudioEffectFilterFactory::~AudioEffectFilterFactory() {

}
AudioEffectFilterFactory *AudioEffectFilterFactory::instance=new AudioEffectFilterFactory();

AudioEffectFilterFactory *AudioEffectFilterFactory::GetInstance() {
    return instance;
}

AudioEffectFilter *AudioEffectFilterFactory::buildFilter(EffectFilterType type) {
    AudioEffectFilter* filter= nullptr;
    switch(type){
        case FilterTypeVocalAGCVolumeAdjustEffect:
            filter=new VocalAGCVolumeAdjustEffectFilter();
            break;


    }

    return filter;
}