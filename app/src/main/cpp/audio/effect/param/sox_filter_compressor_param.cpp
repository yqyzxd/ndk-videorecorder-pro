//
// Created by wind on 2023/7/10.
//

#include "sox_filter_compressor_param.h"

SOXFilterCompressorParam::SOXFilterCompressorParam() {
    this->valid= true;
}
SOXFilterCompressorParam::SOXFilterCompressorParam(float attack, float release, int soft_knee_db,
                                                   int input, int input1, int output1, int input2,
                                                   int output2, int input3, int output3, int input4,
                                                   int output4, int input5, int output5, int input6,
                                                   int output6, int gain, int initial_volume,
                                                   float delay) {
    this->attack=attack;
    this->release=release;
    this->soft_knee_db=soft_knee_db;
    this->input=input;
    this->input1=input1;
    this->input2=input2;
    this->input3=input3;
    this->input4=input4;
    this->input5=input5;
    this->input6=input6;

    this->output1=output1;
    this->output2=output2;
    this->output3=output3;
    this->output4=output4;
    this->output5=output5;
    this->output6=output6;

    this->gain=gain;
    this->initial_volume=initial_volume;
    this->delay=delay;

    this->valid= true;
}

SOXFilterCompressorParam::~SOXFilterCompressorParam() {}

void SOXFilterCompressorParam::setValid(bool valid) {
    this->valid=valid;
}

bool SOXFilterCompressorParam::isValid() {
    return this->valid;
}

void SOXFilterCompressorParam::init(int input1, int output1, int input2, int output2, int input3,
                                    int output3, int input4, int output4, int input5, int output5,
                                    int input6, int output6) {
    this->attack=0.002;
    this->release=0.03;
    this->soft_knee_db=3;
    this->gain=0;
    this->initial_volume=-100;
    this->delay=0.0;
    this->input=-100;

    this->input1 = input1;
    this->output1 = output1;
    this->input2 = input2;
    this->output2 = output2;
    this->input3 = input3;
    this->output3 = output3;
    this->input4 = input4;
    this->output4 = output4;
    this->input5 = input5;
    this->output5 = output5;
    this->input6 = input6;
    this->output6 = output6;
}