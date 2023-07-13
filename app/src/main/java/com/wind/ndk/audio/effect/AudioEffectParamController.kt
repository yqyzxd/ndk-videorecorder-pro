package com.wind.ndk.audio.effect

import android.media.audiofx.Equalizer

/**
 * FileName: AudioEffectParamController
 * Author: wind
 * Date: 2023/7/13 16:11
 * Description:
 * Path:
 * History:
 *  <author> <time> <version> <desc>
 *
 */
object AudioEffectParamController {

    fun extractParam(audioStyle:AudioEffectStyle,equalizer: AudioEffectEQ):AudioEffect{
        if (audioStyle==AudioEffectStyle.LENOVO_EFFECT){

        }


        return AudioEffect.getDefault()
    }

}