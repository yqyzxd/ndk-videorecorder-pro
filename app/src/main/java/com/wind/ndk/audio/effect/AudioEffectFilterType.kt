package com.wind.ndk.audio.effect

/**
 * FileName: AudioEffectFilterType
 * Author: wind
 * Date: 2023/7/14 17:12
 * Description:
 * Path:
 * History:
 *  <author> <time> <version> <desc>
 *
 */
enum class AudioEffectFilterType constructor(var id:Int,name:String) {

    VocalAGCEffectFilter(0,"人声自动音量控制"),
    AccompanyAGCEffectFilter(1,"伴奏自动音量控制"),
    CompressorFilter(2,"压缩效果器"),
    EqualizerFilter(3,"均衡效果器"),
    ReverbEchoFilter(4,"混响+Echo效果器"),
    Mono2StereoFilter(5,"单声道转双声道效果器"),
    AutoTuneEffectFilter(6,"电音效果器"),
    DoubleUEffectFilter(7,"迷幻效果器"),
    HarmonicEffectFilter(8,"唱诗班效果器"),
    VocalPitchShiftFilter(9,"人声升降调效果器"),
    AccompanyPitchShiftFilter(10,"伴奏升降调效果器"),
    VocalVolumeAdjustFilter(11,"人声音量增益效果器"),
    AccompanyVolumeAdjustFilter(12,"伴奏音量增益效果器"),
    FadeOutEffectFilter(13,"淡出效果器"),
    VocalAGCStatEffectFilter(14,"人声自动音量控制的统计Filter"),
    AccompanyAGCStatEffectFilter(15,"人声自动音量控制的统计Filter"),
    VocalDetectEffectFilter(16,"人声段落检测的统计Filter"),
    AccompanyDelayOutputEffectFilter(17,"为了电音做的伴奏的延迟输出效果器")
}