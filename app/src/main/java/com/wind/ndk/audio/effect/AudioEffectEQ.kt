package com.wind.ndk.audio.effect


/**
 * FileName: AudioEffectEQ
 * Author: wind
 * Date: 2023/7/13 15:16
 * Description:
 * Path:
 * History:
 *  <author> <time> <version> <desc>
 *
 */
enum class AudioEffectEQ constructor(id: Int, name: String) {

    BASE_5(0, "低沉5"),
    BASE_4(1, "低沉4"),
    BASE_3(2, "低沉3"),
    BASE_2(3, "低沉2"),
    BASE_1(4, "低沉1"),
    STANDARD(5, "标准"),
    TREBLE_1(6, "明亮1"),
    TREBLE_2(7, "明亮2"),
    TREBLE_3(8, "明亮3"),
    TREBLE_4(9, "明亮4"),
    TREBLE_5(10, "明亮5"),


    LIVE_STANDARD(0, "直播EQ")
    ;


    companion object{
        @JvmStatic
        fun getEnum(eqaulizerId: Int): AudioEffectEQ {
            var eq = STANDARD
            when (eqaulizerId) {
                0 -> eq = BASE_5
                1 -> eq = BASE_4
                2 -> eq = BASE_3
                3 -> eq = BASE_2
                4 -> eq = BASE_1
                5 -> eq = STANDARD
                6 -> eq = TREBLE_1
                7 -> eq = TREBLE_2
                8 -> eq = TREBLE_3
                9 -> eq = TREBLE_4
                10 -> eq = TREBLE_5
            }
            return eq
        }
    }

}