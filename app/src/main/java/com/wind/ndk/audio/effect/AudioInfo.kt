package com.wind.ndk.audio.effect

/**
 * FileName: AudioInfo
 * Author: wind
 * Date: 2023/7/17 10:00
 * Description:
 * Path:
 * History:
 *  <author> <time> <version> <desc>
 *
 */
data class AudioInfo(
    /** 声道数 **/
    private val channels:Int,
    /** 人声的采样频率 **/
    private val audioSampleRate:Int,
    /** 录制的时间 **/
    private val recordedTimeMillis:Int,
    /** 歌曲总时间 **/
    private val totalTimeMillis:Int,
    /** 伴奏的AGC增益 **/
    private val accompanyAGCVolume:Float,
    /** 人声的AGC增益 **/
    private val audioAGCVolume:Float,
    /** 电音 Mel文件路径 **/
    private val melFilePath:String,

    private val accompanyPitch:Float,
    /** Harmonic音效是否仅副歌 **/
    private val harmonicOnlyChorus:Boolean,
    /** Harmonic音效是否是FastMode **/
    private val harmonicFastMode:Boolean,
    /** 录音伴奏变调的级别[-3,3] **/
    private val pitchShiftLevel:Int,
)
