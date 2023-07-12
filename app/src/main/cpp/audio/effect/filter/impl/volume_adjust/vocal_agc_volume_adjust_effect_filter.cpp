//
// Created by wind on 2023/7/12.
//

#include "vocal_agc_volume_adjust_effect_filter.h"
VocalAGCVolumeAdjustEffectFilter::VocalAGCVolumeAdjustEffectFilter() {

}

VocalAGCVolumeAdjustEffectFilter::~VocalAGCVolumeAdjustEffectFilter() {

}

int VocalAGCVolumeAdjustEffectFilter::init(AudioEffect *audioEffect) {
    this->volumeFactor=audioEffect->getAudioInfo()->audioAGCVolume;
    return 0;
}

int VocalAGCVolumeAdjustEffectFilter::filter(AudioRequest *request, AudioResponse *response) {
    short* samples=request->getVocalBuf();
    int sampleSize=request->getVocalBufSize();

    this->process(samples,sampleSize);
}

