#ifndef __aaaaaa__gltb__
#define __aaaaaa__gltb__


#include <OpenGL/gl.h>

void
gltbInit(GLuint button);

void
gltbMatrix(void);

void
gltbReshape(int width, int height);

void
gltbMouse(int button, int state, int x, int y);

void
gltbMotion(int x, int y);

void
gltbAnimate(GLboolean animate);

#endif /* defined(__aaaaaa__gltb__) */