//
// Created by wind on 2023/7/10.
//

#ifndef NDK_VIDEORECORDER_AUDIO_RESPONSE_H
#define NDK_VIDEORECORDER_AUDIO_RESPONSE_H

#include <map>
#include <string>
class AudioResponse {
private:
    std::map<std::string,void*>* mExtraData;
public:
    AudioResponse();
    ~AudioResponse();

    void dealloc();

    void put(std::string key,void* value);
    void* get(std::string key);
};


#endif //NDK_VIDEORECORDER_AUDIO_RESPONSE_H
