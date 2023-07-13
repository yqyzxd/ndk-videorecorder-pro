package com.wind.ndk.audio.effect

/**
 * FileName: SOXReverbParam
 * Author: wind
 * Date: 2023/7/13 17:31
 * Description:
 * Path:
 * History:
 *  <author> <time> <version> <desc>
 *
 */
data class SOXReverbParam(
     val reverberance:Int,
     val damping:Int,
     val roomScale:Int,
     val preDelay:Int,
     val wetGain:Int,
     val stereoDepth:Int,
     val dryWetMix:Int,
     val echoDelay:Int,
     val echoPredecay:Int,
     val echoPeriod:Int,
     val echoDecayRatio:Int,
     val echoPhaseDiff:Int,
     val echoNum:Int
){


    companion object{

        @JvmStatic
        fun getDefault():SOXReverbParam{
            return SOXReverbParam(50,50,50,50,
                8,80,20,20,15,
            30,80,20,2)
        }
    }
}
