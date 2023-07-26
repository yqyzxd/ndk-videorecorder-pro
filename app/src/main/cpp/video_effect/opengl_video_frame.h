//
// Created by wind on 2023/7/26.
//

#ifndef NDK_VIDEORECORDER_PRO_OPENGL_VIDEO_FRAME_H
#define NDK_VIDEORECORDER_PRO_OPENGL_VIDEO_FRAME_H


#include <GLES2/gl2.h>

typedef struct ImagePosition{
    GLint x;
    GLint y;
    GLsizei width;
    GLsizei height;

    ImagePosition(GLint x,GLint y,GLsizei width,GLsizei height){
        this->x=x;
    }
} ImagePosition;


class OpenGLVideoFrame {
public:
    OpenGLVideoFrame();
    OpenGLVideoFrame(GLuint textureId,const ImagePosition& imgPos);
    OpenGLVideoFrame(GLuint textureId,const ImagePosition& imgPos,float position);

    virtual ~OpenGLVideoFrame();


    void init(GLuint textureId,const ImagePosition& imgPos);
    void init(GLuint textureId,const ImagePosition& imgPos,float position);

    float getStreamPosition();
    GLuint getTextureId();
    virtual void getImagePosition(ImagePosition* imgPos);

protected:
    GLuint mTexId;
    float mPosition;
    ImagePosition mImagePos;

};


#endif //NDK_VIDEORECORDER_PRO_OPENGL_VIDEO_FRAME_H
