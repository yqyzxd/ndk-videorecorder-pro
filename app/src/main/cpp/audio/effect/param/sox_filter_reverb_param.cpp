//
// Created by wind on 2023/7/10.
//

#include "sox_filter_reverb_param.h"

SOXFilterReverbParam::SOXFilterReverbParam(int roomSize, int reverberance, int damping,
                                           int stereoWidth) {
    this->roomSize=roomSize;
    this->reverberance=reverberance;
    this->damping=damping;
    this->stereoWidth=stereoWidth;
}

SOXFilterReverbParam::~SOXFilterReverbParam() {}