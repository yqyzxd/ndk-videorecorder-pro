//
// Created by wind on 2023/7/26.
//

#ifndef NDK_VIDEORECORDER_PRO_VIDEO_EFFECT_PROCESSOR_H
#define NDK_VIDEORECORDER_PRO_VIDEO_EFFECT_PROCESSOR_H

#include <string>
#include "opengl_video_frame.h"
#include "video_effect_def.h"
using namespace std;

class VideoEffectProcessor {
public:
    VideoEffectProcessor();
    virtual ~VideoEffectProcessor();

    int init();
    void process(OpenGLVideoFrame* src,float position,OpenGLVideoFrame* dst);
    void dealloc();

    int addFilter(int trackIndex,int64_t sequenceIn,int64_t sequenceOut,string filterName);
    void setFilterParamValue(int trackIndex,int filterId,string paramName,ParamVal value);
    bool invokeFilterOnReady(int trackIndex,int filterId);
    void removeFilter(int trackIndex,int filterId);
    void removeAllFilters();


private:
    OpenGLVideoFrame* mInputVideoFrame;
    OpenGLVideoFrame* mOutputVideoFrame;


};


#endif //NDK_VIDEORECORDER_PRO_VIDEO_EFFECT_PROCESSOR_H
