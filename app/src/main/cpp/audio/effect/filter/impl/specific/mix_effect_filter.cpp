//
// Created by wind on 2023/7/13.
//

#include "mix_effect_filter.h"

MixEffectFilter::MixEffectFilter() {}

MixEffectFilter::~MixEffectFilter() {

}

int MixEffectFilter::init(AudioEffect *audioEffect) {
    return 0;
}

int MixEffectFilter::filter(AudioRequest *request, AudioResponse *response) {
   short* vocalSamples= request->getVocalBuf();
   short* accompanySamples= request->getAccompanyBuf();
   int vocalBufSize=request->getVocalBufSize();

   //todo merge vocal and accompany
}

void MixEffectFilter::dealloc() {

}