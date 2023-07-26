//
// Created by wind on 2023/7/19.
//

#include "sox_base_effect.h"
SOXBaseEffect::SOXBaseEffect() {

}
SOXBaseEffect::SOXBaseEffect(int sampleRate, int channels) {
    mInputSampleRate=sampleRate;
    mInputChannels=channels;
}
SOXBaseEffect::~SOXBaseEffect() {

}

int SOXBaseEffect::init(int bufferSize) {
    initGlobalPrams(bufferSize);
    initEncoding();
    initSignal();
    return 0;
}

void SOXBaseEffect::initGlobalPrams(int bufferSize) {
    sox_globals.bufsiz=bufferSize;
}

void SOXBaseEffect::initEncoding() {
    mEncoding.encoding=(sox_encoding_t)1;
    mEncoding.bits_per_sample=16;
    mEncoding.reverse_bytes=sox_option_no;
    mEncoding.reverse_nibbles=sox_option_no;
    mEncoding.reverse_bits=sox_option_no;
    mEncoding.compression=INFINITY;
    mEncoding.opposite_endian=sox_false;
}

void SOXBaseEffect::initSignal() {
    mSignal.precision=16;
    mSignal.channels=mInputChannels;
    mSignal.rate=mInputSampleRate;
    mSignal.length=mInputSampleRate*mInputChannels*15*60;
    mSignal.mult= nullptr;
}


