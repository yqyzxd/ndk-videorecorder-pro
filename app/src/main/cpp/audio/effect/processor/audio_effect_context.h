//
// Created by wind on 2023/7/10.
//

#ifndef NDK_VIDEORECORDER_AUDIO_EFFECT_CONTEXT_H
#define NDK_VIDEORECORDER_AUDIO_EFFECT_CONTEXT_H

#include <map>
#include <string>
extern "C"{
#include "../../../thirdparty/sox.include/sox.h"
};


class AudioEffectContext {
private:
    std::map<std::string,void*>* mResponse;
    AudioEffectContext();

    static AudioEffectContext* instance;

public:
    ~AudioEffectContext();
    static AudioEffectContext* GetInstance();
    void init();
    void dealloc();

    void copy(std::map<std::string,void*>* src);

};


#endif //NDK_VIDEORECORDER_AUDIO_EFFECT_CONTEXT_H
