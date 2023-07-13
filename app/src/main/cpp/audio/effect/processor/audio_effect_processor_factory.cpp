//
// Created by wind on 2023/7/10.
//

#include "audio_effect_processor_factory.h"


AudioEffectProcessorFactory::AudioEffectProcessorFactory() {}
AudioEffectProcessorFactory::~AudioEffectProcessorFactory() {}

AudioEffectProcessorFactory* AudioEffectProcessorFactory::instance=new AudioEffectProcessorFactory();

AudioEffectProcessorFactory *AudioEffectProcessorFactory::GetInstance() {
    return instance;
}

AudioEffectProcessor *AudioEffectProcessorFactory::buildLiveAudioEffectProcessor() {
    return new AudioEffectLiveProcessor();
}