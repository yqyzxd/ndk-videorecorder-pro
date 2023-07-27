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


int ModelTrack::addFilter(int64_t sequenceIn, int64_t sequenceOut, char *filterName) {
    ModelFilter* filter=createModelFilter(filterCount,sequenceIn,sequenceOut,filterName);
    filters.push_back(filter);
    return filterCount++;
}

bool ModelTrack::invokeFilterOnInit(int filterId) {
    bool ret= false;
    list<ModelFilter*>::iterator iter=filters.begin();
    for(;iter!=filters.end();iter++){
        ModelFilter* item=*iter;
        if (item->getId() == filterId){
            item->onInit();
            break;
        }
    }
    return ret;
}

void ModelTrack::setFilterParamValue(int filterId, char *paramName, ParamVal val) {
   list<ModelFilter*>::iterator iter= filters.begin();
   for(;iter!=filters.end();iter++){
       ModelFilter* item=*iter;
       if (item->getId()==filterId){
           item->setFilterParamValue(paramName,val);
       }
   }
}

bool ModelTrack::getFilterParamValue(int filterId, char *paramName, ParamVal &val) {
    bool ret= false;
    list<ModelFilter*>::iterator iter= filters.begin();
    for(;iter!=filters.end();iter++){
        ModelFilter* item=*iter;
        if (item->getId()==filterId){
           ret= item->getFilterParamValue(paramName,val);
            break;
        }
    }
    return ret;
}

void ModelTrack::deleteFilter(int sub) {
    list<ModelFilter*>::iterator iter= filters.begin();
    for(;iter!=filters.end();){
        ModelFilter* item=*iter;
        if (item->getId()==sub){
            delete item;
            iter=filters.erase(iter);
        }else{
            iter++;
        }
    }
}

list <string> ModelTrack::getAllFilters() {
    list<string> result;
    result.clear();

    list<ModelFilter*>::iterator iter=filters.begin();
    for (; iter !=filters.end() ; ++iter) {
        result.push_back(string((*iter)->name));
    }
    return result;
}

list <string> ModelTrack::getAllTransitions() {
    list<string> result;
    result.clear();

    list<ModelFilter*>::iterator  iter=transitions.begin();
    for (; iter !=transitions.end() ; ++iter) {
        result.push_back(string((*iter)->name));
    }
    return result;
}

int ModelTrack::addTransition(int64_t sequenceIn, int64_t sequenceOut, char *filterName) {
    ModelFilter* transition = createModelFilter(filterCount, sequenceIn, sequenceOut, filterName);
    transitions.push_back(transition);
    return filterCount++;
}

bool ModelTrack::invokeTransitionOnInit(int filterId) {
    bool ret= false;
   list<ModelFilter*>::iterator iter=transitions.begin();
    for(;iter!=transitions.end();iter++){
        if ((*iter)->getId() == filterId){
            (*iter)->onInit();
            break;
        }
    }

    return ret;
}

void ModelTrack::setTransitionParamValue(int filterId, char *paramName, ParamVal val) {
    list<ModelFilter*>::iterator  iter=transitions.begin();
    for(;iter!=transitions.end();iter++){
        if ((*iter)->getId() == filterId){
            (*iter)->setFilterParamValue(paramName,val);
            break;
        }
    }
}