package com.wind.ndk.audio.effect

/**
 * FileName: SOXEqualizerParam
 * Author: wind
 * Date: 2023/7/14 16:57
 * Description:
 * Path:
 * History:
 *  <author> <time> <version> <desc>
 *
 */
data class SOXEqualizerParam(
    private var enable1:Boolean,
    private var frequency1:Int,
    private var bandWidth1:Float,
    private var gain1:Float,

    private var enable2:Boolean,
    private var frequency2:Int,
    private var bandWidth2:Float,
    private var gain2:Float,

    private var enable3:Boolean,
    private var frequency3:Int,
    private var bandWidth3:Float,
    private var gain3:Float,

    private var enable4:Boolean,
    private var frequency4:Int,
    private var bandWidth4:Float,
    private var gain4:Float,

    private var lowpassEnabled:Boolean,
    private var lowpassFrequency:Int,
    private var lowpassBandWidth:Float,

    private var highpassEnabled:Boolean,
    private var highpassFrequency:Int,
    private var highpassBandWidth:Float,
    ){

    companion object{
        @JvmStatic
        fun getDefault():SOXEqualizerParam{
            return SOXEqualizerParam(
                false,500,1.0f,0f,
                false,500,1.0f,0f,
                false,500,1.0f,0f,
                false,500,1.0f,0f,
                false,500,1.0f,
                false,500,1.0f,
            )
        }
    }
}
