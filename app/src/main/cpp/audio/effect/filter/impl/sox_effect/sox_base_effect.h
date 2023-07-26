//
// Created by wind on 2023/7/19.
//

#ifndef NDK_VIDEORECORDER_PRO_SOX_BASE_EFFECT_H
#define NDK_VIDEORECORDER_PRO_SOX_BASE_EFFECT_H


#include "../../../param/sox_filter_chain_param.h"


extern "C"{
#include "../../../../../thirdparty/sox.include/sox.h"
};


class SOXBaseEffect {
protected:
    void initGlobalPrams(int bufferSize);

    int mInputSampleRate;
    int mInputChannels;

    sox_signalinfo_t mSignal;
    void initSignal();
    sox_encodinginfo_t mEncoding;
    void initEncoding();

public:
    SOXBaseEffect();
    SOXBaseEffect(int sampleRate,int channels);
    ~SOXBaseEffect();

    virtual int init(int bufferSize);
    virtual void destroy()=0;
    virtual int initChain(SOXFilterChainParam* filterChainParam)=0;
    virtual void destroyChain()=0;
    virtual int process(short* samples,int sampleSize)=0;
};


#endif //NDK_VIDEORECORDER_PRO_SOX_BASE_EFFECT_H
