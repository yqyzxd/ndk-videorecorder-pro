//
// Created by wind on 2023/7/27.
//

#ifndef NDK_VIDEORECORDER_PRO_THEME_PARSER_H
#define NDK_VIDEORECORDER_PRO_THEME_PARSER_H
#include <string>

typedef bool (*pfnDetectGPUSupportedEffect)(void* context);


static inline bool isFileSuffix(const char* filePath){
    //该函数返回 str 中最后一次出现字符 c 的位置。如果未找到该值，则函数返回一个空指针。
    const char* suffix=strrchr(filePath,'.');
    if (strcmp(suffix,".png")==0 || strcmp(suffix,".mp4")==0){
      return true;
    }
    return false;
}

class ThemeParser {


};


#endif //NDK_VIDEORECORDER_PRO_THEME_PARSER_H
