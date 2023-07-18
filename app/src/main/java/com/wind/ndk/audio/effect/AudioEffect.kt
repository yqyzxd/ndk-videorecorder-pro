package com.wind.ndk.audio.effect


/**
 * FileName: AudioEffect
 * Author: wind
 * Date: 2023/7/13 16:14
 * Description:
 * Path:
 * History:
 *  <author> <time> <version> <desc>
 *
 */
open class AudioEffect(
    private var vocalPitch: Float,
    private var accompanyVolume: Float,
    var audioVolume: Float,
    private var songStyleId: Int,
    private var subId: Int,
    private var vocalEffectFilterChain: List<Int>,
    private var accompanyEffectFilterChain: List<Int>,
    private var mixPostEffectFilterChain: List<Int>
) {


    private lateinit var reverbParam: SOXReverbParam
    private lateinit var compressorParam: SOXCompressorParam
    private lateinit var equalizerParam: SOXEqualizerParam


    private var songStyleName: String = AudioEffectStyle.getEnum(songStyleId).name
    private var subName: String = AudioEffectEQ.getEnum(subId).name
    private var outputGainParam:OutputGainParam = OutputGainParam.getDefault()
    private var adjustEchoReverbParam:AdjustEchoReverbParam = AdjustEchoReverbParam.getDefault()


    private var type=0

    var audioInfo:AudioInfo?=null
    constructor(audioEffect:AudioEffect) : this(audioEffect.vocalPitch,audioEffect.accompanyVolume,
        audioEffect.audioVolume, audioEffect.songStyleId, audioEffect.subId, audioEffect.vocalEffectFilterChain,
        audioEffect.accompanyEffectFilterChain, audioEffect.mixPostEffectFilterChain) {

        this.type=audioEffect.type
        this.audioInfo=audioEffect.audioInfo
        this.reverbParam= SOXReverbParam(audioEffect.reverbParam)
        this.compressorParam= SOXCompressorParam(audioEffect.compressorParam)
        this.equalizerParam=SOXEqualizerParam(audioEffect.equalizerParam)

        if (audioEffect.outputGainParam!=null){
            this.outputGainParam=OutputGainParam(audioEffect.outputGainParam)
        }
        if (audioEffect.adjustEchoReverbParam!=null){
            this.adjustEchoReverbParam= AdjustEchoReverbParam(audioEffect.adjustEchoReverbParam)
        }
    }

    companion object {

        fun getDefault(): AudioEffect {

            val audioEffect = AudioEffect(
                vocalPitch = 1.0f,
                accompanyVolume = 1.0f,
                audioVolume = 1.0f,
                songStyleId = 3,
                subId = 5,
                vocalEffectFilterChain = listOf(),
                accompanyEffectFilterChain = listOf(),
                mixPostEffectFilterChain = listOf()
            )
            audioEffect.reverbParam = SOXReverbParam.getDefault()
            audioEffect.compressorParam = SOXCompressorParam.getDefault()
            audioEffect.equalizerParam = SOXEqualizerParam.getDefault()

            //人声的filter chain
            val vocalFilterChain = listOf(
                AudioEffectFilterType.VocalAGCEffectFilter.id,
                AudioEffectFilterType.CompressorFilter.id,
                AudioEffectFilterType.EqualizerFilter.id,
                AudioEffectFilterType.ReverbEchoFilter.id,
                AudioEffectFilterType.VocalVolumeAdjustFilter.id
            )
            audioEffect.vocalEffectFilterChain=vocalFilterChain

            //伴奏的filter chain
            val accompanyFilterChain= listOf(
                AudioEffectFilterType.AccompanyAGCEffectFilter.id,
                AudioEffectFilterType.AccompanyVolumeAdjustFilter.id,
            )
            audioEffect.accompanyEffectFilterChain=accompanyFilterChain

            //mix之后的filter chain
            val mixPostFilterChain= listOf(
                AudioEffectFilterType.FadeOutEffectFilter.id
            )
            audioEffect.mixPostEffectFilterChain=mixPostFilterChain
            return audioEffect
        }
    }
}