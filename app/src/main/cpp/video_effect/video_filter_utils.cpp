//
// Created by wind on 2023/7/27.
//
#include "video_filter_utils.h"
#include "saturation_scene/saturation_effect.h"
#include "time_stretch/time_stretch_effect.h"

BaseVideoEffect* createVideoEffect(const char* filterName){
    BaseVideoEffect* effect= nullptr;
    if (strcmp(filterName,SATURATION_SCENE_FILTER_NAME)==0){
        effect=new SaturationEffect();
    } else if (strcmp(filterName,TIME_STRETCH_FILTER_NAME)==0){
        effect=new TimeStretchEffect();
    } else if (strcmp(filterName,BEAUTIFY_FACE_COOL_FILTER_NAME)==0){
         effect=new BuautifyFaceCoolEffect();
    } else{
        effect=new BaseVideoEffect();
    }

    return effect;
}

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