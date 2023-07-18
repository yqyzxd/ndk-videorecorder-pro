/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "pcm_collector.h"
#include "effect/audio_effect_adapter.h"
/* Header for class com_wind_ndk_audio_recorder_PcmCollector */

#ifndef _Included_com_wind_ndk_audio_recorder_PcmCollector
#define _Included_com_wind_ndk_audio_recorder_PcmCollector
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_wind_ndk_audio_recorder_PcmCollector
 * Method:    nativeInit
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_wind_ndk_audio_recorder_PcmCollector_nativeInit
  (JNIEnv *, jobject,jint audioSampleRate,jint bufferSizeInShort){
    PcmCollector* collector= new PcmCollector();
    collector->init(audioSampleRate, bufferSizeInShort);
    return reinterpret_cast<jlong>(collector);
}

/*
 * Class:     com_wind_ndk_audio_recorder_PcmCollector
 * Method:    nativeConsume
 * Signature: (J[BI)V
 */
JNIEXPORT void JNICALL Java_com_wind_ndk_audio_recorder_PcmCollector_nativeConsume
  (JNIEnv * env, jobject jobj, jlong ptr, jshortArray array, jint size){
    PcmCollector* collector= reinterpret_cast<PcmCollector *>(ptr);
    jshort* data=env->GetShortArrayElements(array,0);
    collector->collect(data,size);
    env->ReleaseShortArrayElements(array,data,0);
}

/*
 * Class:     com_wind_ndk_audio_recorder_PcmCollector
 * Method:    nativeDealloc
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_wind_ndk_audio_recorder_PcmCollector_nativeDealloc
  (JNIEnv *, jobject, jlong ptr){
    PcmCollector* collector= reinterpret_cast<PcmCollector *>(ptr);
    collector->stop();
}

/*
 * Class:     com_wind_ndk_audio_recorder_PcmCollector
 * Method:    nativeSetAudioEffect
 * Signature: (Lcom/wind/ndk/audio/effect/AudioEffect;)V
 */
JNIEXPORT void JNICALL Java_com_wind_ndk_audio_recorder_PcmCollector_nativeSetAudioEffect
        (JNIEnv * env, jobject jpcmCollector, jlong ptr, jobject jauidoEffect){
    PcmCollector* collector= reinterpret_cast<PcmCollector *>(ptr);
    AudioEffect* audioEffect=AudioEffectAdapter::GetInstance()->buildAudioEffect(env,jauidoEffect);
    collector->setAudioEffect(audioEffect);
}

#ifdef __cplusplus
}
#endif
#endif
