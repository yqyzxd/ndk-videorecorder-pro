//
// Created by wind on 2023/7/19.
//

#ifndef NDK_VIDEORECORDER_PRO_SOX_COMPRESSOR_EFFECT_H
#define NDK_VIDEORECORDER_PRO_SOX_COMPRESSOR_EFFECT_H


#include "sox_base_effect.h"

class SOXCompressorEffect : public SOXBaseEffect{

public:
    static short* sPreProcessSamples;
    static int sSize;
    static short* sResponseData;

protected:
    sox_effects_chain_t* mCompressorChain;
    void initCompressorChain(SOXFilterCompressorParam* compressorParam);

public:
    SOXCompressorEffect(int sampleRate,int channels);
    ~SOXCompressorEffect();

    virtual int init(int bufferSize);
    virtual void destroy();
    virtual int initChain(SOXFilterChainParam* filterChainParam);
    virtual void destroyChain();
    virtual int process(short* samples,int sampleSize);
};


#endif //NDK_VIDEORECORDER_PRO_SOX_COMPRESSOR_EFFECT_H
