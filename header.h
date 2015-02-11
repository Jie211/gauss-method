#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int gauss(double **adim,
	double *xsol, 
	double *bvec, 
	double epsln, 
	int ndata, 
	double **wrk1, 
	double *wrk2);

extern int getmatrix(const char *file, 
	double **a, 
	int ndata);

extern int getvector(const char *file, 
	double *v, 
	int ndata);
