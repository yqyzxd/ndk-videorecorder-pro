//
// Created by wind on 2023/7/11.
//

#include "audio_effect_filter_factory.h"
#include "impl/volume_adjust/accompany_agc_volume_adjust_effect_filter.h"


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
            //人声自动音量控制
            filter=new VocalAGCVolumeAdjustEffectFilter();
            break;
        case FilterTypeAccompanyAGCVolumeAdjustEffect:
            //伴奏自动音量控制
            filter=new AccompanyAGCVolumeAdjustEffectFilter();
            break;

        case FilterTypeCompressor:
            //压缩效果器
            //filter=new CompressorEffectFilter();
            break;

    }

    return filter;
}