//
// Created by wind on 2023/7/26.
//

#include "model_filter.h"

FilterCallback::FilterCallback() {
    mParentFilter= nullptr;
}

FilterCallback::~FilterCallback() {
    mParentFilter= nullptr;
}

void FilterCallback::setParamValue(std::string paramName, ParamVal val) {
    if (mParentFilter!= nullptr){
        mParentFilter->setFilterParamValue((char *)(paramName.c_str()), val);
    }
}

bool FilterCallback::getParamValue(std::string paramName, ParamVal &val) {
    if (mParentFilter== nullptr){
        return false;
    }
    return mParentFilter->getFilterParamValue(paramName,val);
}

void FilterCallback::setParentFilter(ModelFilter *parent) {
    mParentFilter=parent;
}

ModelFilter::ModelFilter() {
    init();
}
ModelFilter::ModelFilter(int index, int64_t sequenceIn, int64_t sequenceOut, char *filterName) {
    init();

    this->mId=index;
    this->mSequenceIn=sequenceIn;
    this->mSequenceOut=sequenceOut;

    int len=0;
    if (filterName){
        len= strlen(filterName);
    }
    if (len>0){
        this->name=new char[len+1];
        memcpy(this->name,filterName,sizeof(char)*(len+1));
    }
}

ModelFilter::~ModelFilter() {
    clear();
}

void ModelFilter::init() {
    mSequenceIn=-1;
    mSequenceOut=-1;

    name= nullptr;
    mMapParamVal.clear();
    pthread_rwlock_init(&mRwLock, nullptr);
    mFilterCallback.setParentFilter(this);
}

void ModelFilter::clear() {
    if (name){
        delete[] name;
        name= nullptr;
    }
    pthread_rwlock_destroy(&mRwLock);
}

void ModelFilter::onRenderPre(float pos) {}

bool ModelFilter::isAvailable(float pos, bool (*pfnDetectGPUSupportedEffect)(void *),
                              void *context) {
    int64_t position=pos * 1000000;
    return position>=mSequenceIn && position<=mSequenceOut;
}

void ModelFilter::setFilterParamValue(char *paramName, ParamVal val) {
    //上写锁
    pthread_rwlock_wrlock(&mRwLock);
    mMapParamVal[string(paramName)]=val;
    //解锁
    pthread_rwlock_unlock(&mRwLock);
}

bool ModelFilter::getFilterParamValue(std::string paramName, ParamVal &val) {
    bool founded= false;
    //上读锁
    pthread_rwlock_rdlock(&mRwLock);
    map<string,ParamVal>::iterator iter=mMapParamVal.find(paramName);
    if (iter!=mMapParamVal.end()){
        val=iter->second;
        founded= true;
    }
    //解锁
    pthread_rwlock_unlock(&mRwLock);
    return founded;
}

EffectCallback *ModelFilter::getFilterCallback() {
    return (EffectCallback*) (&mFilterCallback);
}