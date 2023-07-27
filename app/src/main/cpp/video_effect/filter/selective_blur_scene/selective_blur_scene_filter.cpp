//
// Created by wind on 2023/7/27.
//

#include "selective_blur_scene_filter.h"
SelectiveBlurSceneFilter::SelectiveBlurSceneFilter() {}

SelectiveBlurSceneFilter::SelectiveBlurSceneFilter(int index, int64_t sequenceIn,
                                                   int64_t sequenceOut, char *filterName):
        ModelFilter(index,sequenceIn,sequenceOut,filterName){

}
SelectiveBlurSceneFilter::~SelectiveBlurSceneFilter() {
    clear();
}

bool SelectiveBlurSceneFilter::isAvailable(float pos, bool (*pfnDetectGPUSupportedEffect)(void *),
                                           void *context) {
    if (ModelFilter::isAvailable(pos,pfnDetectGPUSupportedEffect,context)){
        if (pfnDetectGPUSupportedEffect!= nullptr){
            return pfnDetectGPUSupportedEffect(context);
        }
    }
    return false;
}