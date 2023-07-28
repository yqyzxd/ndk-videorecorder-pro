//
// Created by wind on 2023/7/27.
//

#ifndef NDK_VIDEORECORDER_PRO_VIDEO_FILTER_UTILS_H
#define NDK_VIDEORECORDER_PRO_VIDEO_FILTER_UTILS_H

#include "model_filter.h"
#include "video_effect_params.h"
#include "filter/selective_blur_scene/selective_blur_scene_filter.h"
#include "base_video_effect.h"

BaseVideoEffect* createVideoEffect(const char* filterName);

ModelFilter* createModelFilter(int filterIndex, int64_t sequenceIn, int64_t sequenceOut, char* filterName);


#endif //NDK_VIDEORECORDER_PRO_VIDEO_FILTER_UTILS_H
