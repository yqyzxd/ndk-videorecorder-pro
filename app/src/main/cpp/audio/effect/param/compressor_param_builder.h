//
// Created by wind on 2023/7/19.
//

#ifndef NDK_VIDEORECORDER_PRO_COMPRESSOR_PARAM_BUILDER_H
#define NDK_VIDEORECORDER_PRO_COMPRESSOR_PARAM_BUILDER_H

#include "sox_filter_compressor_param.h"

#define POINT_COUNT 6
/*
 * 单例设计，在录制过程中（PacketConsumer），算出分贝的分布，在完成录音界面（RealtimeEcho），计算出压缩效果器参数
 */
class CompressorParamBuilder {
private:
    long* mSamplesDistribution;
    CompressorParamBuilder();
    static CompressorParamBuilder* instance;

public:
    static CompressorParamBuilder* GetInstance();
    virtual ~CompressorParamBuilder();

    SOXFilterCompressorParam* buildFilterCompressorParam();
    SOXFilterCompressorParam* buildFilterCompressorParamWithFactor(float attackTime,float decayTime,int threshold,
                                                                      float ratio,int expansion_threshold,float expansion_ratio,int gain);

};


#endif //NDK_VIDEORECORDER_PRO_COMPRESSOR_PARAM_BUILDER_H
