//
// Created by wind on 2023/7/26.
//

#ifndef NDK_VIDEORECORDER_PRO_MODEL_TRACK_H
#define NDK_VIDEORECORDER_PRO_MODEL_TRACK_H


#include "model_filter.h"
#include <list>
#include "video_filter_utils.h"

class ModelTrack {
public:
    ModelTrack();
    virtual ~ModelTrack();

    void clear();
    void clearFilters();
    void clearTransitions();

    list<ModelFilter*> getAllFilter(){
        list<ModelFilter*> result;
        list<ModelFilter*>::iterator iter=transitions.begin();
        for(;iter!=transitions.end();iter++){
            result.push_back(*iter);
        }
        iter=filters.begin();
        for (; iter !=filters.end() ; iter++) {
            result.push_back(*iter);
        }
        return result;
    }
    const list<ModelFilter*> getFilterList(){
        return filters;
    }

    int addTransition(int64_t sequenceIn,int64_t sequenceOut,char* filterName);
    void setTransitionParamValue(int filterId,char* paramName,ParamVal val);
    bool invokeTransitionOnInit(int filterId);
    list<string> getAllTransitions();

    int addFilter(int64_t sequenceIn,int64_t sequenceOut,char* filterName);
    void deleteFilter(int sub);
    bool invokeFilterOnInit(int filterId);
    void setFilterParamValue(int filterId, char* paramName,ParamVal val);
    bool getFilterParamValue(int filterId,char* paramName,ParamVal& val);
    list<string> getAllFilters();

protected:
    int index;
    list<ModelFilter*> filters;
    list<ModelFilter*> transitions;
    int filterCount;

};


#endif //NDK_VIDEORECORDER_PRO_MODEL_TRACK_H
