//
// Created by wind on 2023/7/10.
//

#ifndef NDK_VIDEORECORDER_SOX_FILTER_REVERB_PARAM_H
#define NDK_VIDEORECORDER_SOX_FILTER_REVERB_PARAM_H

/**
 * 混响效果器，就是接受一个输入的声音，然后进行某种计算（卷积），达到多种声音叠加的效果。
 * 每个空间都有自己独特的混响特征，也就是有自己独特的IR（impluse response脉冲反应）
 *
 * 特定场景IR的获取方式：
 * 方式一：采用IR混响，全部是真实采样得来的wave文件，采样混响的IR都是由录音采样得来。
 * 方式二：算法混响
 *
 *混响的第一个声音是直达声，也就是源声音，在效果器里叫dry out(干声输出)，随后几个相隔
 * 比较开的声音叫"早反射声"，它们都是只经过几次反射就到达的声音，声音比较大， 比较明显。
 */
class SOXFilterReverbParam {
private:
    /**空间大小 空间可以体现出声场的宽度和纵深度，不同的效果器在该参数上有不同的算法体现*/
    int roomSize;

    /**余响大小 如果早反射声可以决定空间的距离，那么余响可代表空间的构造，即空间里物体多少，墙壁材质，物体表面材质越松软，代表吸音的能力越强，余响越小*/
    int reverberance;
    /**阻尼控制 代表混响声音减弱的程度，对应到实际场景中就是场景里的物体多少。物体越多，且物体表面越不光滑，衰减就越厉害*/
     int damping;

     /**立体声宽度 有的混响效果器有这样的参数，值越大，效果器在产生IR时会使左右声道差异变大，最终产生立体声效果*/
     int stereoWidth;

public:
    SOXFilterReverbParam(int roomSize,int reverberance,int damping,int stereoWidth);
    ~SOXFilterReverbParam();

    int getRoomSize(){
        return roomSize;
    }

    int getReverberance(){
        return reverberance;
    }
    int getDamping(){
        return damping;
    }
    int getStereoWidth(){
        return stereoWidth;
    }
};


#endif //NDK_VIDEORECORDER_SOX_FILTER_REVERB_PARAM_H
