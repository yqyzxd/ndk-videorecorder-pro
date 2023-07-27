//
// Created by wind on 2023/7/27.
//

#ifndef NDK_VIDEORECORDER_PRO_SELECTIVE_BLUR_SCENE_H
#define NDK_VIDEORECORDER_PRO_SELECTIVE_BLUR_SCENE_H


#include "../../model_filter.h"

class SelectiveBlurSceneFilter: public ModelFilter{
public:
    SelectiveBlurSceneFilter();
    SelectiveBlurSceneFilter(int index,int64_t sequenceIn,int64_t sequenceOut,char* filterName);
    virtual ~SelectiveBlurSceneFilter();

    virtual bool isAvailable(float pos,bool (*pfnDetectGPUSupportedEffect)(void* context),void* context);
};


#endif //NDK_VIDEORECORDER_PRO_SELECTIVE_BLUR_SCENE_H
