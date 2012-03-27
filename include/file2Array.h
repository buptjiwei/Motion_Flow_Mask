#include "cv.h"
#include "highgui.h"

int inRange ( float tmin, float tmax, float data);
void SkinFilter_LUV(IplImage* inputImg, IplImage * pmask);
void imgShow ( char *name, IplImage *img);
