//
// Created by wind on 2023/7/10.
//

#ifndef NDK_VIDEORECORDER_AUDIO_INFO_H
#define NDK_VIDEORECORDER_AUDIO_INFO_H


typedef struct AudioInfo {
    int channels;
    int sampleRate;

    float accompanyAGCVolume;
    float audioAGCVolume;
    float accompanyPitch;
    int pitchShiftLevel;


}AudioInfo;


#endif //NDK_VIDEORECORDER_AUDIO_INFO_H
