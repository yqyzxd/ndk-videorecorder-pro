//
// Created by wind on 2023/7/10.
//

#include "sox_filter_equalizer_param.h"


SOXFilterEqualizerParam::SOXFilterEqualizerParam(int type, int frequency, float bandWidth,
                                                 int gain) {
    this->type=type;
    this->frequency=frequency;
    this->bandWidth=bandWidth;
    this->gain=gain;
}

SOXFilterEqualizerParam::~SOXFilterEqualizerParam() {}