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
class AudioEffect(
    private var vocalPitch: Float,
    private var accompanyVolume: Float,
    private var audioVolume: Float,
    private var songStyleId: Int,
    private var subId: Int,
    private var vocalEffectFilterChain: List<Int>,
    private var accompanyEffectFilterChain: List<Int>,
    private var mixPostEffectFilterChain: List<Int>
) {
    private var songStyleName: String
    private var subName: String

    private var reverbParam: SOXReverbParam? = null
    private var compressorParam: SOXCompressorParam? = null
    private var equalizerParam: SOXEqualizerParam? = null




    init {
        songStyleName = AudioEffectStyle.getEnum(songStyleId).name
        subName = AudioEffectEQ.getEnum(subId).name
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