//
// Created by wind on 2023/7/10.
//

#ifndef NDK_VIDEORECORDER_SOX_FILTER_CHAIN_PARAM_H
#define NDK_VIDEORECORDER_SOX_FILTER_CHAIN_PARAM_H


#include "sox_filter_compressor_param.h"
#include "sox_filter_equalizer_param.h"
#include "sox_filter_reverb_param.h"
#include <list>

class SOXFilterChainParam {
private:
    int mVolume;

    SOXFilterCompressorParam* mSOXFilterCompressorParam;
    std::list<SOXFilterEqualizerParam*>* mSOXFilterEqualizerParams;
    SOXFilterReverbParam* mSOXFilterReverbParam;
    //混响所占比例
    float reverbRatio;
};


#endif //NDK_VIDEORECORDER_SOX_FILTER_CHAIN_PARAM_H
