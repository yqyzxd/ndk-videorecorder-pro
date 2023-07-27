//
// Created by wind on 2023/7/26.
//

#include "model_timeline.h"

ModelTimeline::ModelTimeline() {

}
ModelTimeline::~ModelTimeline() {
    clear();
}

void ModelTimeline::init() {
    clear();

    ModelTrack* track=new ModelTrack();
    mTracks.push_back(track);
}

void ModelTimeline::clear() {
   list<ModelTrack*>::iterator iter=mTracks.begin();
   for(;iter!=mTracks.end();){
       delete *iter;
       iter=mTracks.erase(iter);
   }
}

void ModelTimeline::clearFilters() {
    list<ModelTrack*>::iterator iter=mTracks.begin();
    (*iter)->clearFilters();
}

int ModelTimeline::addFilter(int trackIndex, int64_t sequenceIn, int64_t sequenceOut,
                             char *filterName) {
    list<ModelTrack*>::iterator iter=mTracks.begin();
    return (*iter)->addFilter(sequenceIn,sequenceOut,filterName);
}

void ModelTimeline::removeFilter(int trackIndex, int filterId) {
    list<ModelTrack*>::iterator iter=mTracks.begin();
    (*iter)->deleteFilter(filterId);
}

bool ModelTimeline::invokeFilterOnInit(int trackIndex, int filterId) {
    list<ModelTrack*>::iterator iter=mTracks.begin();
    return (*iter)->invokeFilterOnInit(filterId);
}

void
ModelTimeline::setFilterParamValue(int trackIndex, int filterId, char *paramName, ParamVal val) {
    list<ModelTrack*>::iterator iter=mTracks.begin();
    (*iter)->setFilterParamValue(filterId,paramName,val);
}

bool
ModelTimeline::getFilterParamValue(int trackIndex, int filterId, char *paramName, ParamVal &val) {
    list<ModelTrack*>::iterator iter=mTracks.begin();
    return (*iter)->getFilterParamValue(filterId,paramName,val);
}

int ModelTimeline::addTransition(int trackIndex, int64_t sequenceIn, int64_t sequenceOut,
                                 char *filterName) {
    list<ModelTrack*>::iterator iter=mTracks.begin();
    return (*iter)->addTransition(sequenceIn,sequenceOut,filterName);
}

void
ModelTimeline::setTransitionParamVal(int trackIndex, int filterId, char *paramName, ParamVal val) {
    list<ModelTrack*>::iterator iter=mTracks.begin();
    (*iter)->setTransitionParamValue(filterId,paramName,val);
}

bool ModelTimeline::invokeTransitionOnInit(int trackIndex, int filterId) {
    list<ModelTrack*>::iterator iter=mTracks.begin();
    (*iter)->invokeTransitionOnInit(filterId);
}

list<ModelFilter *> ModelTimeline::getAllTranAndFilters(int trackIndex) {
    list<ModelTrack*>::iterator iter=mTracks.begin();
    return (*iter)->getAllFilter();
}