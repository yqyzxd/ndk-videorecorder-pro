//
// Created by 史浩 on 2023/6/24.
//

#ifndef NDK_VIDEORECORDER_MUSIC_MERGER_H
#define NDK_VIDEORECORDER_MUSIC_MERGER_H

#include "../effect/audio_effect.h"
#include "../effect/processor/audio_effect_processor.h"

//将伴奏和录音合并成一轨
class MusicMerger {
public:
    MusicMerger();
    ~MusicMerger();

    int mergeMusic(short* accompanySamples,int accompanySize,int* accompanySamplesCursor,short* audioSamples,int audioSize,int* audioSamplesCursor);

    void initWithAudioEffectProcessor(int audioSampleRate, AudioEffect *audioEffect);

    void dealloc();
private:
    int mAudioSampleRate=0;
    AudioEffectProcessor* mAudioEffectProcessor= nullptr;

    short mixSamples(short accompany, short audio);
};


#endif //NDK_VIDEORECORDER_MUSIC_MERGER_H
