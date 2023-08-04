//
// Created by wind on 2023/7/28.
//

#ifndef NDK_VIDEORECORDER_PRO_BEAUTIFY_FACE_COOL_EFFECT_H
#define NDK_VIDEORECORDER_PRO_BEAUTIFY_FACE_COOL_EFFECT_H


#include "../group_video_effect.h"
#include "smooth_skin_horizontal_effect.h"
#include "smooth_skin_vertical_effect.h"
#include "hue_effect.h"
#include "tone_curve_effect.h"
#include "sharpen_effect.h"
class BeautifyFaceCoolEffect: public GroupVideoEffect{
public:
    BeautifyFaceCoolEffect();
    ~BeautifyFaceCoolEffect();



};


#endif //NDK_VIDEORECORDER_PRO_BEAUTIFY_FACE_COOL_EFFECT_H
