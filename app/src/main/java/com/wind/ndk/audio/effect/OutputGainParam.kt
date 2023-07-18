package com.wind.ndk.audio.effect

import androidx.core.view.ContentInfoCompat.Flags

/**
 * FileName: OutputGainParam
 * Author: wind
 * Date: 2023/7/17 09:50
 * Description:
 * Path:
 * History:
 *  <author> <time> <version> <desc>
 *
 */
data class OutputGainParam(
    private val gain:Float
){

    constructor(param: OutputGainParam):this(param.gain)

    companion object{
        @JvmStatic
        fun getDefault():OutputGainParam{
            return OutputGainParam(1.0f)
        }
    }
}
