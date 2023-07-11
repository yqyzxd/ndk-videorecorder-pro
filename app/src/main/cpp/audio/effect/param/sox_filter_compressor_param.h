//
// Created by wind on 2023/7/10.
//

#ifndef NDK_VIDEORECORDER_SOX_FILTER_COMPRESSOR_PARAM_H
#define NDK_VIDEORECORDER_SOX_FILTER_COMPRESSOR_PARAM_H

/**
 * 压缩器效果器，是指在时域上对声音强度所进行的一个处理，也可以理解为当音频的音量剧增时，自动将音量调小一点。
 */
class SOXFilterCompressorParam {
private:
    bool valid;
    /**作用时间，用于决定在超过门限值后多久触发压缩器来工作*/
    float attack;
    /**释放时间，决定在低于门限值多长时间之后停止工作*/
    float release;

    /**输出增益，即增益补偿，用于提升整个输出信息，就可以将压缩掉的动态空间补偿回来*/
    int gain;

    int soft_knee_db;
    int input;
    int input1;
    int output1;
    int input2;
    int output2;
    int input3;
    int output3;
    int input4;
    int output4;
    int input5;
    int output5;
    int input6;
    int output6;

    int initial_volume;
    float delay;

public:
    SOXFilterCompressorParam(float attack, float release, int soft_knee_db,
                             int input, int input1, int output1, int input2, int output2,
                             int input3, int output3, int input4, int output4, int input5,
                             int output5, int input6, int output6, int gain, int initial_volume, float delay);
    ~SOXFilterCompressorParam();

   /* void init(int input1, int output1, int input2, int output2,
              int input3, int output3, int input4, int output4, int input5,
              int output5, int input6, int output6);
    */

   void setValid(bool valid);
   bool isValid();


};


#endif //NDK_VIDEORECORDER_SOX_FILTER_COMPRESSOR_PARAM_H
