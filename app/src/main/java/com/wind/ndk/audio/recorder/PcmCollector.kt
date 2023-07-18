package com.wind.ndk.audio.recorder

import com.wind.ndk.audio.effect.AudioEffect

/**
 * FileName: PcmConsumer
 * Author: wind
 * Date: 2023/5/30 10:07
 * Description:
 * Path:
 * History:
 *  <author> <time> <version> <desc>
 *
 */
class PcmCollector(private val audioSampleRate:Int,private val bufferSizeInShort:Int) :AudioRecorder.Consumer,AudioRecorder.AudioEffectSetter {
    private var ptr:Long=0



    override fun begin() {
        ptr= nativeInit(audioSampleRate,bufferSizeInShort)
    }

    override fun consume(shortArray: ShortArray, sizeInShort: Int) {
        nativeConsume(ptr,shortArray,sizeInShort)
    }

    override fun end() {
        nativeDealloc(ptr)
    }
    override fun setAudioEffect(audioEffect: AudioEffect) {
        nativeSetAudioEffect(ptr,audioEffect)
    }
    private external fun nativeInit(audioSampleRate:Int, bufferSizeInShort:Int): Long
    private external fun nativeConsume(ptr: Long, shortArray: ShortArray, sizeInShort: Int)
    private external fun nativeDealloc(ptr: Long)

    private external fun nativeSetAudioEffect(ptr: Long,audioEffect: AudioEffect)


}