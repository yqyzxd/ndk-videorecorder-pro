//
// Created by wind on 2023/7/18.
//

#include "audio_effect_adapter.h"

AudioEffectAdapter::AudioEffectAdapter() {}

AudioEffectAdapter::~AudioEffectAdapter() {}

AudioEffectAdapter* AudioEffectAdapter::instance=new AudioEffectAdapter();

AudioEffectAdapter *AudioEffectAdapter::GetInstance() {
    return instance;
}


AudioEffect *AudioEffectAdapter::buildAudioEffect(JNIEnv *env, jobject jaudioEffect) {
    AudioEffect* audioEffect= nullptr;
    jclass  jaudioEffectClass=env->GetObjectClass(jaudioEffect);
    jmethodID  getTypeMethodID=env->GetMethodID(jaudioEffectClass,"getType","()I");
    jint type=env->CallIntMethod(jaudioEffect,getTypeMethodID);
    AudioEffectBuilder* builder=getAudioEffectBuilder(type);
    if (builder!= nullptr){
        audioEffect= builder->buildAudioEffect(env,jaudioEffect);
        audioEffect->setType(type);
        delete builder;
    }

    return audioEffect;

}


