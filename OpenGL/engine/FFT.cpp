
#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "engine/FFT.h"
#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif
int    FFT(int,int,float *,float *);
int    FFT2D(Complex **, int,int,int);
int    DFT(int,int,float *,float *);
int    Powerof2(int,int *,int *);

/*-------------------------------------------------------------------------
   This computes an in-place complex-to-complex FFT
   x and y are the real and imaginary arrays of 2^m points.
   dir =  1 gives forward transform
   dir = -1 gives reverse transform

     Formula: forward
                  N-1
                  ---
              1   \          - j k 2 pi n / N
      X(n) = ---   >   x(k) e                    = forward transform
              N   /                                n=0..N-1
                  ---
                  k=0

      Formula: reverse
                  N-1
                  ---
                  \          j k 2 pi n / N
      x(n) =       >   X(k) e                    = reverse transform?
                  /                                n=0..N-1
                  ---
                  k=0
*/
int FFT(int dir,int m,float *x,float *y)
{
   long nn,i,i1,j,k,i2,l,l1,l2;
   float c1,c2,tx,ty,t1,t2,u1,u2,z;

   /* Calculate the number of points 
   nn = 1;
   for (i=0;i<m;i++)
      nn *= 2;
	*/
	nn = 1 << m;

   /* Do the bit reversal */
   i2 = nn >> 1;
   j = 0;
   for (i=0;i<nn-1;i++) {
      if (i < j) {
         tx = x[i];
         ty = y[i];
         x[i] = x[j];
         y[i] = y[j];
         x[j] = tx;
         y[j] = ty;
      }
      k = i2;
      while (k <= j) {
         j -= k;
         k >>= 1;
      }
      j += k;
   }

   /* Compute the FFT */
   c1 = -1.0;
   c2 = 0.0;
   l2 = 1;
   for (l=0;l<m;l++) {
      l1 = l2;
      l2 <<= 1;
      u1 = 1.0;
      u2 = 0.0;
      for (j=0;j<l1;j++) {
         for (i=j;i<nn;i+=l2) {
            i1 = i + l1;
            t1 = u1 * x[i1] - u2 * y[i1];
            t2 = u1 * y[i1] + u2 * x[i1];
            x[i1] = x[i] - t1;
            y[i1] = y[i] - t2;
            x[i] += t1;
            y[i] += t2;
         }
         z =  u1 * c1 - u2 * c2;
         u2 = u1 * c2 + u2 * c1;
         u1 = z;
      }
      c2 = sqrt((1.0 - c1) / 2.0);
      if (dir == 1)
         c2 = -c2;
      c1 = sqrt((1.0 + c1) / 2.0);
   }

   /* Scaling for forward transform */
   if (dir == 1) {
      for (i=0;i<nn;i++) {
         x[i] /= (float)nn;
         y[i] /= (float)nn;
      }
   }

   return(TRUE);
}

/*-------------------------------------------------------------------------
   Perform a 2D FFT inplace given a complex 2D array
   The direction dir, 1 for forward, -1 for reverse
   The size of the array (nx,ny)
   Return false if there are memory problems or
      the dimensions are not powers of 2
*/
//int FFT2D(Complex **c,int nx,int ny,int dir)
int FFT2D(Complex c[][64],int nx,int ny,int dir)
{
   int i,j;
   int m,twopm;
   float *real,*imag;

   /* Transform the rows */
   real = (float *)malloc(nx * sizeof(float));
   imag = (float *)malloc(nx * sizeof(float));
   if (real == NULL || imag == NULL)
      return(FALSE);
   if (!Powerof2(nx,&m,&twopm) || twopm != nx)
      return(FALSE);
   for (j=0;j<ny;j++) {
      for (i=0;i<nx;i++) {
         real[i] = c[i][j].real;
         imag[i] = c[i][j].imag;
      }
      FFT(dir,m,real,imag);
      for (i=0;i<nx;i++) {
         c[i][j].real = real[i];
         c[i][j].imag = imag[i];
      }
   }
   free(real);
   free(imag);

   /* Transform the columns */
   real = (float *)malloc(ny * sizeof(float));
   imag = (float *)malloc(ny * sizeof(float));
   if (real == NULL || imag == NULL)
      return(FALSE);
   if (!Powerof2(ny,&m,&twopm) || twopm != ny)
      return(FALSE);
   for (i=0;i<nx;i++) {
      for (j=0;j<ny;j++) {
         real[j] = c[i][j].real;
         imag[j] = c[i][j].imag;
      }
      FFT(dir,m,real,imag);
      for (j=0;j<ny;j++) {
         c[i][j].real = real[j];
         c[i][j].imag = imag[j];
      }
   }
   free(real);
   free(imag);

   return(TRUE);
}

/*-------------------------------------------------------------------------
        Direct fourier transform
*/
int DFT(int dir,int m,float *x1,float *y1)
{
   long i,k;
   float arg;
   float cosarg,sinarg;
	float *x2=NULL,*y2=NULL;

	x2 =(float *) malloc(m*sizeof(float));
   y2 = (float *)malloc(m*sizeof(float));
	if (x2 == NULL || y2 == NULL)
		return(FALSE);

   for (i=0;i<m;i++) {
      x2[i] = 0;
      y2[i] = 0;
      arg = - dir * 2.0 * 3.141592654 * (float)i / (float)m;
      for (k=0;k<m;k++) {
         cosarg = cos(k * arg);
         sinarg = sin(k * arg);
         x2[i] += (x1[k] * cosarg - y1[k] * sinarg);
         y2[i] += (x1[k] * sinarg + y1[k] * cosarg);
      }
   }

   /* Copy the data back */
   if (dir == 1) {
      for (i=0;i<m;i++) {
         x1[i] = x2[i] / (float)m;
         y1[i] = y2[i] / (float)m;
      }
   } else {
      for (i=0;i<m;i++) {
         x1[i] = x2[i];
         y1[i] = y2[i];
      }
   }

	free(x2);
	free(y2);
   return(TRUE);
}

/*-------------------------------------------------------------------------
	Calculate the closest but lower power of two of a number
	twopm = 2**m <= n
	Return TRUE if 2**m == n
*/
int Powerof2(int n,int *m,int *twopm)
{
	if (n <= 1) {
		*m = 0;
		*twopm = 1;
		return(FALSE);
	}

   *m = 1;
   *twopm = 2;
   do {
      (*m)++;
      (*twopm) *= 2;
   } while (2*(*twopm) <= n);

   if (*twopm != n) 
		return(FALSE);
	else
		return(TRUE);
}