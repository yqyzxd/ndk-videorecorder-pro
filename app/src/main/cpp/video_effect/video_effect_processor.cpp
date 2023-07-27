//
// Created by wind on 2023/7/26.
//

#include "video_effect_processor.h"

VideoEffectProcessor::VideoEffectProcessor(){
    mTimeline=new ModelTimeline();
    mTimeline->init();
    pthread_rwlock_init(&mRwLock, nullptr);
}
VideoEffectProcessor::~VideoEffectProcessor() {

}

void VideoEffectProcessor::process(OpenGLVideoFrame *src, float position, OpenGLVideoFrame *dst) {


}

int VideoEffectProcessor::addFilter(int trackIndex, int64_t sequenceIn, int64_t sequenceOut,
                                    std::string filterName) {

    return 0;
}

void VideoEffectProcessor::setFilterParamValue(int trackIndex, int filterId, std::string paramName,
                                               ParamVal value) {

}

bool VideoEffectProcessor::invokeFilterOnReady(int trackIndex, int filterId) {
    return true;
}

void VideoEffectProcessor::removeFilter(int trackIndex, int filterId) {

}

void VideoEffectProcessor::removeAllFilters() {

}
void VideoEffectProcessor::dealloc() {

}
