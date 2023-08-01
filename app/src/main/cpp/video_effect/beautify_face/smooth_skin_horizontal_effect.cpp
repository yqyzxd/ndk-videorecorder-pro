//
// Created by wind on 2023/8/1.
//

#include "smooth_skin_horizontal_effect.h"
SmoothHorizontalSkinEffect::SmoothHorizontalSkinEffect(): BaseVideoEffect(OPTIMIZED_SKIN_HORIZONTAL_VERTEX_SHADER,OPTIMIZED_SKIN_HORIZONTAL_FRAG_SHADER) {


    uTexelWidthOffsetLocation=glGetUniformLocation(mProgram,"u_TexelWidthOffset");
    uTexelHeightOffsetLocation=glGetUniformLocation(mProgram,"u_TexelHeightOffset");
    


}


void SmoothHorizontalSkinEffect::inflateLocation(GLuint textureId) {
    BaseVideoEffect::inflateLocation(textureId);
    /** 设置FadeIn的Progress **/
    glUniform1f(uTexelWidthOffsetLocation, 0.0);
    glUniform1f(uTexelHeightOffsetLocation, (GLfloat)(getHighpassRadius() / mHeight));
}
