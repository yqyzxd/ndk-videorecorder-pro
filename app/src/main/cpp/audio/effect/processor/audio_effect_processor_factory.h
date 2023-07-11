//
// Created by wind on 2023/7/10.
//

#ifndef NDK_VIDEORECORDER_AUDIO_EFFECT_PROCESSOR_FACTORY_H
#define NDK_VIDEORECORDER_AUDIO_EFFECT_PROCESSOR_FACTORY_H


#include "audio_effect_processor.h"

class AudioEffectProcessorFactory {
private:
    AudioEffectProcessorFactory();
    static AudioEffectProcessorFactory* instance;

public:
    static AudioEffectProcessorFactory* GetInstance();
    ~AudioEffectProcessorFactory();


    AudioEffectProcessor* buildAudioEffectProcessor();

};


#endif //NDK_VIDEORECORDER_AUDIO_EFFECT_PROCESSOR_FACTORY_H
