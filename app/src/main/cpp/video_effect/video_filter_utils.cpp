//
// Created by wind on 2023/7/27.
//
#include "video_filter_utils.h"

ModelFilter* createModelFilter(int filterIndex,int64_t sequenceIn,int64_t sequenceOut,char* filterName){
    ModelFilter* result= nullptr;
    if (strcmp(filterName,CONTRAST_FILTER_NAME)==0){
        result =new ModelFilter(filterIndex,sequenceIn,sequenceOut,filterName);
    } else if (strcmp(filterName,SELECTIVE_BLUR_SCENE_FILTER_NAME)==0){
        result=new SelectiveBlurSceneFilter(filterIndex,sequenceIn,sequenceOut,filterName);
    } else{
        return new ModelFilter(filterIndex,sequenceIn,sequenceOut,filterName);
    }

    return result;
}