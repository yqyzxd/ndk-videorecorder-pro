//
// Created by wind on 2023/7/19.
//

#include "compressor_param_builder.h"

CompressorParamBuilder::CompressorParamBuilder() {
    mSamplesDistribution=new long [POINT_COUNT*2];
    for (int i=0;i<POINT_COUNT*2;i++){
        mSamplesDistribution[i]=0;
    }
}
CompressorParamBuilder* CompressorParamBuilder::instance=new CompressorParamBuilder();
CompressorParamBuilder *CompressorParamBuilder::GetInstance() {
    return instance;
}

CompressorParamBuilder::~CompressorParamBuilder() {
    if(mSamplesDistribution!= nullptr){
        delete[] mSamplesDistribution;
        mSamplesDistribution= nullptr;
    }
}

static short Rank_dB[12] = { -55, -50, -45, -40, -35, -30, -25, -20, -15, -10, -6, 0 };
static short Rank_Amp[12] = { 58, 104, 184, 328, 583, 1036, 1843, 3277, 5827, 10362, 16423, 32767 };


SOXFilterCompressorParam *CompressorParamBuilder::buildFilterCompressorParam() {
    SOXFilterCompressorParam* param=new SOXFilterCompressorParam();

    //todo

    return param;
}

SOXFilterCompressorParam *
CompressorParamBuilder::buildFilterCompressorParamWithFactor(float attackTime, float decayTime,
                                                             int threshold, float ratio,
                                                             int expansion_threshold,
                                                             float expansion_ratio, int gain) {
    SOXFilterCompressorParam* param=new SOXFilterCompressorParam();
    int input1 = -75;
    int output1 = -100;
    int input2 = -20;
    int output2 = -20;
    int input3 = -15;
    int output3 = -15;
    int input4 = -10;
    int output4 = -11.3;
    int input5 = -6;
    int output5 = -9.2;
    int input6 = 0;
    int output6 = -6.7;

    if(input1<input2 && input2<input3 && input3<input4 && input4<input5){

        param->init(input1,output1,input2,output2,input3,output3,input4,output4,input5,output5,input6,output6);
        param->setAttackTime(attackTime);
        param->setDecayTime(decayTime);
        param->setGain(gain);
    }


    return param;

}