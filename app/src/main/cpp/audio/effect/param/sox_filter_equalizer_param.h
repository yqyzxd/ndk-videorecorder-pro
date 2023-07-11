//
// Created by wind on 2023/7/10.
//

#ifndef NDK_VIDEORECORDER_SOX_FILTER_EQUALIZER_PARAM_H
#define NDK_VIDEORECORDER_SOX_FILTER_EQUALIZER_PARAM_H

/**
 * 均衡效果器参数
 *
 * 均衡效果器又称为均衡器（Equalizer），其最大的作用就是决定声音的远近层次。
 * 我们时常听到别人说这首歌曲是重金属风格的歌曲，或者说这首歌曲是舞曲风格等，
 * 其实就与声音的远近层次有关。不同歌曲风格的区别在于声音在不同频段的提升或衰减。
 */
class SOXFilterEqualizerParam {
private:
    /**
     * Bass Boost: 低音增强
     * Bass Cut: 低音截断（类似高通滤波器）
     * Treble Boost: 高音增强
     * Treble Cut: 高音截断（类似于低通滤波器）
     * Telephone: 代表电话音质（频率分布在400~3000Hz范围）
     * AM Radio: 代表收音机音质（频率分布在50~400Hz范围）
     */
    int type;
    /**代表哪一个频率*/
    int frequency;
    /**频宽，表示均衡器修正的不是某个单一频率上的声音而是一个频段的声音。*/
    float bandWidth;
    /**对frequency 指向的频率修正，代表增益是多少*/
    int gain;
public:
    SOXFilterEqualizerParam(int type,int frequency,float bandWidth,int gain);
    ~SOXFilterEqualizerParam();

    int getType(){
        return type;
    }

    int getFrequency(){
        return frequency;
    }
    float getBandWidth(){
        return bandWidth;
    }

    int getGain(){
        return gain;
    }

};


#endif //NDK_VIDEORECORDER_SOX_FILTER_EQUALIZER_PARAM_H
