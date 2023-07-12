//
// Created by wind on 2023/7/12.
//

#ifndef NDK_VIDEORECORDER_PRO_VOCAL_AGC_VOLUME_ADJUST_EFFECT_FILTER_H
#define NDK_VIDEORECORDER_PRO_VOCAL_AGC_VOLUME_ADJUST_EFFECT_FILTER_H


#include "volume_adjust_effect_filter.h"

class VocalAGCVolumeAdjustEffectFilter : public VolumeAdjustEffectFilter{
public:
    VocalAGCVolumeAdjustEffectFilter();
    ~VocalAGCVolumeAdjustEffectFilter();

     int init(AudioEffect* audioEffect);
     int filter(AudioRequest* request,AudioResponse* response);
};


#endif //NDK_VIDEORECORDER_PRO_VOCAL_AGC_VOLUME_ADJUST_EFFECT_FILTER_H
