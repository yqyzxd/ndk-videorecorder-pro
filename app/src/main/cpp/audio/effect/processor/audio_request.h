//
// Created by wind on 2023/7/10.
//

#ifndef NDK_VIDEORECORDER_AUDIO_REQUEST_H
#define NDK_VIDEORECORDER_AUDIO_REQUEST_H

#include <map>
#include <string>
class AudioRequest {
private:
    short *mVocalBuf;
    int mVocalBufSize;

    short *mAccompanyBuf;
    int mAccompanyBufSize;
    //需要处理的bufSize
    int mHandleSize;

    float mPosition;
    long mFrameSize;
    std::map<std::string, void *> *mExtraData;

public:
    AudioRequest();
    ~AudioRequest();

    void init(short *vocalBuf, int vocalBufSize, float position, long frameSize);
    void init(short* vocalBuf,int vocalBufSize,short* accompanyBuf,int accompanyBufSize,int handleSize);
    void initAccompany(short *accompanyBuf, int accompanyBufSize, float position, long frameSize);


    short* getVocalBuf() {
        return mVocalBuf;
    }
    int getVocalBufSize(){
        return mVocalBufSize;
    }
    short* getAccompanyBuf() {
        return mAccompanyBuf;
    }
    int getAccompanyBufSize(){
        return mAccompanyBufSize;
    }

    int getHandleSize(){
        return mHandleSize;
    }
};


#endif //NDK_VIDEORECORDER_AUDIO_REQUEST_H
