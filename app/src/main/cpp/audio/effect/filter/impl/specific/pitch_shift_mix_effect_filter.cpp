//
// Created by wind on 2023/7/13.
//

#include "pitch_shift_mix_effect_filter.h"


PitchShiftMixEffectFilter::PitchShiftMixEffectFilter() {
    mAccompanyBufQueue= nullptr;
    mVocalBufQueue= nullptr;
}

PitchShiftMixEffectFilter::~PitchShiftMixEffectFilter() {

}

int PitchShiftMixEffectFilter::init(AudioEffect *audioEffect) {
    mAudioSampleRate=audioEffect->getAudioInfo()->sampleRate;
    mChannels=2;
    mAccompanyBufCursor=0;
    mVocalBufCursor=0;
    return 0;
}

int PitchShiftMixEffectFilter::filter(AudioRequest *request, AudioResponse *response) {

    int accompanySampleSize=request->getAccompanyBufSize();
    int vocalSampleSize=request->getVocalBufSize();
    if (mBufQueueSize==0 && mAccompanyBufQueue== nullptr && mVocalBufQueue== nullptr){
        mBufQueueSize=MAX(vocalSampleSize*4,mAudioSampleRate*mChannels);
        mAccompanyBufQueue=new short[mBufQueueSize];
        mVocalBufQueue=new short[mBufQueueSize];
    }
    int* accompanyReceiveSamplesSize=(int*)response->get(KEY_ACCOMPANY_RESPONSE_RECEIVE_SAMPLES_SIZE);
    if (accompanyReceiveSamplesSize!= nullptr){
        accompanySampleSize=*accompanyReceiveSamplesSize;
        delete accompanyReceiveSamplesSize;
    }

    int* vocalReceiveSamplesSize=(int*)response->get(KEY_VOCAL_RESPONSE_RECEIVE_SAMPLES_SIZE);
    if (vocalReceiveSamplesSize!= nullptr){
        vocalSampleSize=*vocalReceiveSamplesSize;
        delete vocalReceiveSamplesSize;
    }

    //todo
}

void PitchShiftMixEffectFilter::dealloc() {

}