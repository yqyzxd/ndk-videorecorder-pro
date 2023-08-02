//
// Created by wind on 2023/7/28.
//

#include "group_video_effect.h"

GroupVideoEffect::GroupVideoEffect() {
    mEffects=new std::list<BaseVideoEffect*>();
}

GroupVideoEffect::~GroupVideoEffect()  {
    if(NULL != mEffects){
        mEffects->clear();
        delete mEffects;
        mEffects = NULL;
    }
}

void GroupVideoEffect::onReady(int width, int height) {
    BaseFilter::onReady(width,height);
    list<BaseVideoEffect*>::iterator iter=mEffects->begin();
    for(;iter!=mEffects->end();iter++){
        BaseVideoEffect* effect=*iter;
        effect->onReady(width,height);
    }
}
void GroupVideoEffect::addEffect(BaseVideoEffect *effect) {
    mEffects->push_back(effect);
}

GLuint GroupVideoEffect::onDrawFrame(GLuint textureId) {
    list<BaseVideoEffect*>::iterator iter=mEffects->begin();
    for(;iter!=mEffects->end();iter++){
        BaseVideoEffect* effect=*iter;
        textureId=effect->onDrawFrame(textureId);
    }

    return textureId;
}

void GroupVideoEffect::dealloc() {
    BaseFilter::dealloc();
    list<BaseVideoEffect*>::iterator iter=mEffects->begin();
    for(;iter!=mEffects->end();iter++){
        BaseVideoEffect* effect=*iter;
        effect->dealloc();
    }
}