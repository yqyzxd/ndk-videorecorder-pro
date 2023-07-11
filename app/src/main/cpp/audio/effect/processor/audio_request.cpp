//
// Created by wind on 2023/7/10.
//

#include "audio_request.h"
AudioRequest::AudioRequest() {
    mExtraData=new std::map<std::string,void*>();
}

AudioRequest::~AudioRequest() {}

void AudioRequest::init(short *vocalBuf, int vocalBufSize, float position, long frameSize) {
    mVocalBuf=vocalBuf;
    mVocalBufSize=vocalBufSize;
    mPosition=position;
    mFrameSize=frameSize;
}

void
AudioRequest::init(short *vocalBuf, int vocalBufSize, short *accompanyBuf, int accompanyBufSize,
                   float position, long frameSize) {
    mVocalBuf=vocalBuf;
    mVocalBufSize=vocalBufSize;
    mPosition=position;
    mFrameSize=frameSize;

    mAccompanyBuf=accompanyBuf;
    mAccompanyBufSize=accompanyBufSize;
}

void AudioRequest::initAccompany(short *accompanyBuf, int accompanyBufSize, float position,
                                 long frameSize) {
    mAccompanyBuf=accompanyBuf;
    mAccompanyBufSize=accompanyBufSize;
    mPosition=position;
    mFrameSize=frameSize;
}