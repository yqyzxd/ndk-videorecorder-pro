//
// Created by wind on 2023/7/26.
//

#ifndef NDK_VIDEORECORDER_PRO_MODEL_FILTER_H
#define NDK_VIDEORECORDER_PRO_MODEL_FILTER_H

#include "video_effect_def.h"
#include <string>
#include <map>
using namespace std;

class ModelFilter;
class FilterCallback :public EffectCallback{
public:
    FilterCallback();
    ~FilterCallback();

public:
    virtual bool getParamValue(string paramName,ParamVal& val);
    virtual void setParamValue(string paramName,ParamVal val);
    void setParentFilter(ModelFilter* parent);

protected:
    ModelFilter* mParentFilter;
};

class ModelFilter {
public:
    ModelFilter();
    ModelFilter(int index,int64_t sequenceIn,int64_t sequenceOut,char* filterName);
    ~ModelFilter();

    void init();
    virtual bool onInit(){
        return true;
    }
    virtual void onRenderPre(float pos);
    virtual void clear();
    virtual bool isAvailable(float position,bool (*pfnDetectGPUSupportedEffect)(void* context),void* context);
    void setFilterParamValue(char* paramName,ParamVal val);
    bool getFilterParamValue(string paramName,ParamVal& val);
    EffectCallback* getFilterCallback();

    int getId(){
        return mId;
    }

public:
    char* name;

protected:
    int mId;
    int64_t mSequenceIn;
    int64_t mSequenceOut;
    pthread_rwlock_t mRwLock;
    map<string,ParamVal> mMapParamVal;
    FilterCallback mFilterCallback;
};


#endif //NDK_VIDEORECORDER_PRO_MODEL_FILTER_H
