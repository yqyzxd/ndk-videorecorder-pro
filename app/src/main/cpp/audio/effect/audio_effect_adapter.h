//
// Created by wind on 2023/7/18.
//

#ifndef NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_ADAPTER_H
#define NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_ADAPTER_H


#include "audio_effect_builder.h"
typedef enum AudioEffectType_t{
    BASE_AUDIO_EFFECT_TYPE,//原声|留声机|迷幻|流行|摇滚|舞曲|新世纪|R&B|LIVE_XXX
    AUTO_TUNE_EFFECT_TYPE,//电音
    ROBOT_EFFECT_TYPE,//机器人
    LENOVO_EFFECT_TYPE,//联想乐蒙特效
    HARMONIC,//和声音效
    ADJUST_ECHO_REVERB_EFFECT_TYPE //超级混响
} AudioEffectType_t;
class AudioEffectAdapter {
private:
    AudioEffectAdapter();
    static AudioEffectAdapter* instance;

    AudioEffectBuilder* getAudioEffectBuilder(int type){
        AudioEffectBuilder* builder= new AudioEffectBuilder();
        switch (type) {
            case AUTO_TUNE_EFFECT_TYPE:
                //AutoTuneAudioEffectBuilder();
                break;
            case ROBOT_EFFECT_TYPE:
                //RobotAudioEffectBuilder();
                break;
            case HARMONIC:
                break;
            case ADJUST_ECHO_REVERB_EFFECT_TYPE:
                break;
            case BASE_AUDIO_EFFECT_TYPE:
            case LENOVO_EFFECT_TYPE:
            default:
                builder=new AudioEffectBuilder();
                break;
        }

        return builder;
    }

public:
    static AudioEffectAdapter* GetInstance();
    ~AudioEffectAdapter();

    AudioEffect* buildAudioEffect(JNIEnv* env,jobject audioEffect);
    //AudioEffect* buildRecordingAudioEffect(JNIEnv* env,jobject audioEffect);

};


#endif //NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_ADAPTER_H
