//
// Created by wind on 2023/7/26.
//

#include "model_track.h"

ModelTrack::ModelTrack() {
    filterCount=0;
}
ModelTrack::~ModelTrack() {
    clear();
}

void ModelTrack::clear() {
    this->clearFilters();
    this->clearTransitions();
}

void ModelTrack::clearFilters() {
   list<ModelFilter*>::iterator iter=filters.begin();
   for(;iter!=filters.end();iter++){
       delete *iter;
       iter= filters.erase(iter);
   }
}

void ModelTrack::clearTransitions() {
    list<ModelFilter*>::iterator iter=transitions.begin();
    for(;iter!=transitions.end();iter++){
        delete *iter;
        iter=transitions.erase(iter);
    }
}