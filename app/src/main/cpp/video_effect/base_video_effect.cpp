//
// Created by wind on 2023/7/27.
//

#include "base_video_effect.h"
BaseVideoEffect::BaseVideoEffect(const char *vertexSource, const char *fragmentSource):
                BaseFboFilter(vertexSource,fragmentSource) {

}

BaseVideoEffect::~BaseVideoEffect() noexcept {

}

