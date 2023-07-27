//
// Created by wind on 2023/7/26.
//

#ifndef NDK_VIDEORECORDER_PRO_MODEL_TIMELINE_H
#define NDK_VIDEORECORDER_PRO_MODEL_TIMELINE_H

#include <list>
#include "model_filter.h"
#include "model_track.h"
using namespace std;
class ModelTimeline {
public:
    ModelTimeline();
    virtual ~ModelTimeline();
    
    void init();
    void clear();
    void clearFilters();
    
    list<ModelFilter*> getAllTranAndFilters(int trackIndex);
    void removeFilter(int trackIndex,int filterId);
    int addTransition(int trackIndex,int64_t sequenceIn,int64_t sequenceOut,char* filterName);
    void setTransitionParamVal(int trackIndex,int filterId,char* paramName,ParamVal val);
    bool invokeTransitionOnInit(int trackIndex,int filterId);

    int addFilter(int trackIndex,int64_t sequenceIn,int64_t sequenceOut,char* filterName);
    void setFilterParamValue(int trackIndex, int filterId,char* paramName,ParamVal val);
    bool getFilterParamValue(int trackIndex,int filterId,char* paramName,ParamVal& val);
    bool invokeFilterOnInit(int trackIndex,int filterId);

protected:
    list<ModelTrack*> mTracks;
};


#endif //NDK_VIDEORECORDER_PRO_MODEL_TIMELINE_H
