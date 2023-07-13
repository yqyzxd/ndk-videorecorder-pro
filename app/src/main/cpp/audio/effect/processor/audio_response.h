//
// Created by wind on 2023/7/10.
//

#ifndef NDK_VIDEORECORDER_AUDIO_RESPONSE_H
#define NDK_VIDEORECORDER_AUDIO_RESPONSE_H

#define KEY_VOCAL_RESPONSE_RECEIVE_SAMPLES_SIZE  "key_vocal_response_receive_samples_size"
#define KEY_ACCOMPANY_RESPONSE_RECEIVE_SAMPLES_SIZE  "key_accompany_response_receive_samples_size"
#define KEY_ACCOMPANY_RESPONSE_PITCHSHIFT_UNPROCESS_SIZE "key_accompany_response_pitchshift_unprocess_size"

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
