//
// Created by wind on 2023/7/12.
//

#ifndef NDK_VIDEORECORDER_PRO_VOLUME_ADJUST_EFFECT_FILTER_H
#define NDK_VIDEORECORDER_PRO_VOLUME_ADJUST_EFFECT_FILTER_H


#include "../../../audio_effect.h"
#include "../../audio_effect_filter.h"
#include "../../../volume_adjuster.h"

class VolumeAdjustEffectFilter : public AudioEffectFilter{

private:
    VolumeAdjuster* mVolumeAdjuster;

protected:
    float volumeFactor;
    void process(short* samples,int sampleSize){
        if (mVolumeAdjuster== nullptr){
            mVolumeAdjuster=new VolumeAdjuster();
        }
        mVolumeAdjuster->adjustVolume(samples,sampleSize,this->volumeFactor);
    }

public:

    virtual int init(AudioEffect* audioEffect)=0;
    virtual int filter(AudioRequest* request,AudioResponse* response)=0;
    void dealloc(){};
};


#endif //NDK_VIDEORECORDER_PRO_VOLUME_ADJUST_EFFECT_FILTER_H
