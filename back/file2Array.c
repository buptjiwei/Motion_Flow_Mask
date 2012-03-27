//#include "skinFilter.h"
#include "file2Array.h"

void imgShow ( char *name, IplImage *img)
{
	cvNamedWindow ( name, 1);
	cvShowImage ( name, img);
	cvWaitKey (0);
	cvDestroyWindow ( name);
	cvReleaseImage ( &img);	
}

int inRange ( float tmin, float tmax, float data)
{
	int flag;
	if ( data >= tmin && data <= tmax)
                return 1;
        else
                return 0;

}

void SkinFilter_LUV(IplImage* inputImg, IplImage * pmask)
{
	cvSmooth ( inputImg, pmask, CV_BLUR, 3, 3, 0, 0);	
}
