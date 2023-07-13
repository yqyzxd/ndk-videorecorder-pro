package com.wind.ndk.audio.effect

/**
 * FileName: en
 * Author: wind
 * Date: 2023/7/13 15:00
 * Description:
 * Path:
 * History:
 *  <author> <time> <version> <desc>
 *
 */
enum class AudioEffectStyle constructor(val id:Int,  name:String){

    ORIGINAL(0,"原生"),
    GRAMOPHONE(1,"留声机"),
    CAT(2,"萌猫"),
    DOG(3,"狗宝宝"),
    BABY(4,"娃娃音"),
    RNB(5,"R&B"),
    ROCK(6,"摇滚"),
    POPULAR(7,"流行"),
    DANCE(8,"舞曲"),
    NEW_CENT(9,"新世纪"),
    LIVE_ORIGINAL(10,"直播原声"),
    LIVE_MAGIC(11,"直播魔音"),
    LIVE_SIGNER(12,"直播唱将"),
    LIVE_PROFESSION(13,"直播专业"),
    LIVE_GOD(14,"直播顶尖"),
    LENOVO_EFFECT(15,"乐檬特效"),
    AUTO_TUNE(16,"电音"),
    DOUBLE_YOU(17,"DOUBLE YOU"),
    ROBOT(18,"机器人"),
    RECORDING_ACCOMPANY_PITCHSHIFT(19,"录音伴奏变调"),
    HARMONIC(20,"和声音效")
    ;


    companion object{

       fun getEnum(id:Int):AudioEffectStyle{
           var result=when(id){
               0-> ORIGINAL
               1-> GRAMOPHONE
               2->CAT
               3->DOG
               4->BABY
               5->RNB
               6->ROCK
               7->POPULAR
               8->DANCE
               9->NEW_CENT
               10->LIVE_ORIGINAL
               11->LIVE_MAGIC
               12->LIVE_SIGNER
               13->LIVE_PROFESSION
               14->LIVE_GOD
               16->AUTO_TUNE
               17->DOUBLE_YOU
               18->ROBOT
               19->RECORDING_ACCOMPANY_PITCHSHIFT
               20->HARMONIC
               else -> {
                   ORIGINAL
               }
           }

           return result
       }
    }


}