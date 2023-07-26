//
// Created by wind on 2023/7/19.
//

#include "accompany_agc_volume_adjust_effect_filter.h"
AccompanyAGCVolumeAdjustEffectFilter::AccompanyAGCVolumeAdjustEffectFilter() {}

AccompanyAGCVolumeAdjustEffectFilter::~AccompanyAGCVolumeAdjustEffectFilter() {}

int AccompanyAGCVolumeAdjustEffectFilter::init(AudioEffect *audioEffect) {
    this->volumeFactor=audioEffect->getAudioInfo()->accompanyAGCVolume;
    return 0;
}

int AccompanyAGCVolumeAdjustEffectFilter::filter(AudioRequest *request, AudioResponse *response) {
    short* samples=request->getAccompanyBuf();
   // int sampleSize=request->getAccompanyBufSize();
    int handleSize=request->getHandleSize();

    this->process(samples,handleSize);
}

