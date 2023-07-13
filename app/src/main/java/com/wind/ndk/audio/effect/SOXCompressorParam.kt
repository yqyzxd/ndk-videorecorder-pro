package com.wind.ndk.audio.effect

import android.util.FloatMath

/**
 * FileName: SOXCompressorParam
 * Author: wind
 * Date: 2023/7/13 17:43
 * Description:
 * Path:
 * History:
 *  <author> <time> <version> <desc>
 *
 */
data class SOXCompressorParam(
    private val attackTime:Float,
    private val decayTime:Float,
    private val threshold:Int,
    private val ratio:Float,
    private val expansionThreshold:Int,
    private val expansionRatio:Float,
    private val gain:Int
){

    companion object{
        @JvmStatic
        fun getDefault():SOXCompressorParam{
            return SOXCompressorParam(
                0.02f,0.04f,20,1.5f,
                25,1.3f,0)
        }
    }
}
