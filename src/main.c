#include <stdio.h>
#include "cv.h"
#include "highgui.h"
#include "cxcore.h"
#include "cvaux.h"
#include "file2Array.h"

int main( int argc, char ** argv)
{
	FILE *myfile;
    char buffer[100];
    int i,j;
	int iN, iPixN;
	if ( argc < 2)
	{
		printf ( "usage: ./cmd <filename> < pren> <postn>\n");
		exit (-1);
	}
//	int pren = atoi ( argv[2]);
//	int postn = atoi ( argv[3]);
//	int iPixN = atoi ( argv[4]);
//	int iN = postn - pren + 1;

	double ** str ;
//	str =  (double **)malloc ( sizeof (double *) * iN);
	if ( !str) printf ( "malloc error str\n");

    if (( myfile = fopen(argv[1],"r")) == NULL)
	{
		printf("%s Read File Error\n", argv[1]);
		exit(-1);
	}
    i =0, j=0;	

	fscanf ( myfile, "%d %d\n", &iN,&iPixN);
	//fscanf ( myfile, "%d", &iPixN);
	str =  (double **)malloc ( sizeof (double *) * iN);
//	iN = 69; 
//	iPixN = 147456;
	printf ( " %d -- %d\n", iN, iPixN);
	for ( i=0; i < iN-1; i ++)
	{
		printf ( "line no: %d\n", i+1);
//		* ( str + i) =  malloc ( sizeof ( double) * iPixN);
		str[i] = ( double *)malloc ( sizeof ( double) * iPixN);
		if ( ! ( * ( str + i))) printf ( "%d malloc error\n", i);
		float tmp=0;
		for ( j=0; j < iPixN-1; j ++)
		{
	//		fflush (stdin);
			fscanf ( myfile, "%f ", &tmp );
//		if ( i > 60) {printf ( "%f\n", tmp); }
		//	*(* ( str + i) + j) = tmp;
		str[i][j] = tmp;
		}
		fscanf ( myfile, "%f \n", &tmp );
	//	printf ( "%f\n", tmp);
       // *(* ( str + i) + iPixN-1 ) = tmp;
	   str[i][iPixN-1] = tmp;
	}


	 * ( str + iN - 1) =  malloc ( sizeof ( double) * iPixN);
	float tmp=0;
    for ( j=0; j < iPixN-1; j ++)
    {
	    fscanf ( myfile, "%f ", &tmp );
	//	printf ( "%f\n", tmp);
	    *(* ( str + iN -1) + j) = tmp;

	}
						
	// printf ( "hello %d -- %d\n", iN, iPixN);	
	fscanf ( myfile, "%f \n", &tmp );
	printf ( "%f\n", tmp);
	*(* ( str + iN -1) + iPixN-1 ) = tmp;
	 printf ( "sssssss%f\n", tmp);

	fclose ( myfile);
	printf ( "Done %d -- %d\n", iN, iPixN);

/*
	for ( i=0; i<iN; i++)
	{
		for ( j=0; j<iPixN; j ++)
		{
			//printf ( "%lf	", data2[i][j]);
			printf ( "%lf ", * (* ( str + i) + j));
		}
		printf ("\n");
	}

*/



/*
	// tst the main file
	printf("hello world\n");
	// tst comm func in h file
	if ( inRange(1,3,2)) printf("right of comm func in h\n");
	else { printf("wrong inRange\n"); exit(0);}
	
	
	IplImage * src = cvLoadImage(argv[1], 1);
	IplImage * dst = cvCreateImage ( cvGetSize(src), src->depth, 3);
	// initial
	cvZero (dst);
	// skin Filter eg smooth file 
	SkinFilter_LUV ( src, dst);

	imgShow ("src",	src);	
	imgShow ("dst", dst);
	//return 0;
	
*/
}
