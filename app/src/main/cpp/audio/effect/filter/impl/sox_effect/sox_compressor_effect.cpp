//
// Created by wind on 2023/7/19.
//

#include "sox_compressor_effect.h"

SOXCompressorEffect::SOXCompressorEffect(int sampleRate, int channels): SOXBaseEffect(sampleRate,channels) {
    mCompressorChain= nullptr;
}
SOXCompressorEffect::~SOXCompressorEffect() {}

short* SOXCompressorEffect::sPreProcessSamples= nullptr;
int SOXCompressorEffect::sSize= 0;
short* SOXCompressorEffect::sResponseData= nullptr;

int SOXCompressorEffect::init(int bufferSize) {
    sResponseData=new short[bufferSize*2];
    return SOXBaseEffect::init(bufferSize);
}

void SOXCompressorEffect::destroy() {
    if (sResponseData!= nullptr){
        delete[] sResponseData;
        sResponseData= nullptr;
    }
}

int SOXCompressorEffect::initChain(SOXFilterChainParam *filterChainParam) {
    SOXBaseEffect::initSignal();

}

void SOXCompressorEffect::destroyChain() {
    if ( mCompressorChain!= nullptr) {
        sox_delete_effects_chain(mCompressorChain);
    }
}

int SOXCompressorEffect::process(short *samples, int sampleSize) {
    //todo

    return 0;
}