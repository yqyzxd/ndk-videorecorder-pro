//
// Created by wind on 2023/7/11.
//

#ifndef NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_FILTER_FACTORY_H
#define NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_FILTER_FACTORY_H

typedef enum EffectFilterType{
    FilterTypeVocalAGCVolumeAdjustEffect,//人声自动音量控制的音量调节
    FilterTypeAccompanyAGCVolumeAdjustEffect,//伴奏自动音量控制的音量调节
    FilterTypeCompressor,//压缩效果器
    FilterTypeEqualizer,//均衡效果器
    FilterTypeReverbEcho,//混响+echo效果器
    FilterTypeMono2Stereo,//单声道转双声道效果器
    FilterTypeAutoTuneEffect,//电音效果器
    FilterTypedDoubleUEffect,//迷幻效果器
    FilterTypeHarmonicEffect,//唱诗班效果器
    FilterTypeVocalPitchShift,//人声升降调效果器
    FilterTypeAccompanyPitchShift,//伴奏升降调效果器
    FilterTypeVocalVolumeAdjust,//人声音量增益效果器
    FilterTypeAccompanyVolumeAdjust,//伴奏音量增益效果器
    FilterTypeFadeOutEffect,//淡出效果器
    FilterTypeVocalAGCStatEffect,//人声自动音量控制的统计
    FilterTypeAccompanyAGCStatEffect,//伴奏自动音量控制的统计
    FilterTypeVocalDetectEffect,//人声段落检测的统计
    FilterTypeAccompanyDelayOutputEffect,//为了电音做的伴奏的延迟输出效果器
    FilterTypeVocalVolumeBalanceAdjust,//7.0新增人声音量增益效果器
    FilterTypeAccompanyVolumeBalanceAdjust,//7.0新增伴奏音量增益效果器
    FilterTypeStereoReverbEcho,//支持双声道输入的混响+echo效果器
    FilterTypeAdjustEchoReverb,//7.0新增支持可调节的echo+reverb
    FilterTypeVocalVolumeDetectEffect // 7.0新增只用来检测人声音量，目前用在包房直播人声音量检测


}EffectFilterType;

class AudioEffectFilterFactory {

};


#endif //NDK_VIDEORECORDER_PRO_AUDIO_EFFECT_FILTER_FACTORY_H
