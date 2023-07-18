package com.wind.ndk.audio.effect

import java.util.PrimitiveIterator

/**
 * FileName: AdjustEchoReverbParam
 * Author: wind
 * Date: 2023/7/17 09:53
 * Description:
 * Path:
 * History:
 *  <author> <time> <version> <desc>
 *
 */
data class AdjustEchoReverbParam(
    //超级混响音效echo，范围[0，1]
    private var adjustEchoEffectRatio:Float,
    //超级混响音效reverb，范围[0，1]
    private var adjustReverbEffectRatio:Float
){

    constructor(param: AdjustEchoReverbParam):this(param.adjustEchoEffectRatio,param.adjustReverbEffectRatio)

    companion object{
        @JvmStatic
        fun getDefault():AdjustEchoReverbParam{
            return AdjustEchoReverbParam(1.0f,1.0f)
        }
    }
}
