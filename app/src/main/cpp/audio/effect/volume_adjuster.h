//
// Created by wind on 2023/7/12.
//

#ifndef NDK_VIDEORECORDER_PRO_VOLUME_ADJUSTER_H
#define NDK_VIDEORECORDER_PRO_VOLUME_ADJUSTER_H


class VolumeAdjuster {
public:
    VolumeAdjuster();
    ~VolumeAdjuster();

    void adjustVolume(short* samples,int sampleSize,float volumeFactor);
    short adjust(short sample, float factor);
};


#endif //NDK_VIDEORECORDER_PRO_VOLUME_ADJUSTER_H
