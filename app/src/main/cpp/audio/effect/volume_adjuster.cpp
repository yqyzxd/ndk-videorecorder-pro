//
// Created by wind on 2023/7/12.
//

#include <cstdint>
#include "volume_adjuster.h"

VolumeAdjuster::VolumeAdjuster() {

}

VolumeAdjuster::~VolumeAdjuster() {

}

void VolumeAdjuster::adjustVolume(short *samples, int sampleSize, float volumeFactor) {
    if(volumeFactor!=1.0f){
        for (int i = 0; i < sampleSize; ++i) {
            samples[i]=adjust(samples[i],volumeFactor);
        }
    }

}

short VolumeAdjuster::adjust(short sample, float factor) {
    int result=((int)sample)*factor;

    //16进制的8000，也就十进制的32768.
    if(result<-INT16_MIN){
        result=INT16_MIN;
    } else if(result > INT16_MAX){
        result=INT16_MAX;
    }

    return result;
}
