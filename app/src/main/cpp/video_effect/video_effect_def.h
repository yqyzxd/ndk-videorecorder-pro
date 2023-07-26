//
// Created by wind on 2023/7/26.
//

#ifndef NDK_VIDEORECORDER_PRO_VIDEO_EFFECT_DEF_H
#define NDK_VIDEORECORDER_PRO_VIDEO_EFFECT_DEF_H
#include <string>


enum EffectParamType{

    EffectParamTypeInvalid=-1,
    EffectParamTypeArbitrary=0,
    EffectParamTypeInt,
    EffectParamTypeFloat,
    EffectParamTypeBoolean,
    EffectParamTypeString,
    EffectParamTypeColor,
    EffectParamTypePosition2D,
    EffectParamTypePosition3D,
    EffectParamTypePath
};


struct Color{
    float r,g,b,a;
};


struct Position2D{
    float x,y;
};
struct Position3D{
    float x,y,z;
};

struct ParamVal{
    union {
        void* arbitrary;
        int intVal;
        double fltVal;
        bool boolVal;
        Color colorVal;
        Position2D pos2DVal;
        Position3D pos3DVal;
    } u;
    std::string strVal;

};

class EffectCallback{
public:
    virtual bool getParamValue(std::string paramName,ParamVal& val)=0;
    virtual void setParamValue(std::string paramName,ParamVal val)=0;
};

#endif //NDK_VIDEORECORDER_PRO_VIDEO_EFFECT_DEF_H
