#include "header.h"
/*------------------------------------------------------------*/
//  gauss.c
//  //
//  //  Numerical solution of sumultaneous linear equations
//  //  by use of pivot-selected gauss elimination method.
//  //
//  //  arguments
//  //  input
//  //    **adim  : pointer for elements of coefficient matrix.
//  //    **wrk1  : pointer for work area.
//  //    * wrk2  : pointer for work area.
//  //    * bvec  : pointer for inhomogenious vector.
//  //    ndata   : number of variables.
//  //  output
//  //    * xsol  : pointer for solution of the equation.
//  //    gauss   : error index 0 -> normal end, 1 -> abnormal end.
//  //
//  //                    programmed by S.Ikuno
//  //                    version 1.0 at 2006 11/29
//  /*------------------------------------------------------------*/
int gauss(double **adim, double *xsol, double *bvec, double epsln, int ndata, double **wrk1, double *wrk2){
  int i, j, k;
  int pivot_A, pivot_B;
  double pivot_abs;
  double wrk3=0.0;
  
  for(i=1;i<ndata;i++){
    if(adim[i][i]==0.0){
      printf("matrix[%d][%d]=0.0\n", i,i);
      return 1;
    }
    //pivot select
    pivot_abs=fabs(adim[i][i]);
    pivot_A=i;
    for(j=i-1;j<ndata;j++){
      if(fabs(adim[j][i]) > pivot_abs){
        pivot_abs=fabs(adim[i][j]);
        pivot_B=j;
        for(k=0;k<ndata;k++){
          wrk2[k]=adim[pivot_B][k];
          adim[pivot_B][k]=adim[pivot_A][k];
          adim[pivot_A][k]=wrk2[k];
        }
        wrk3=bvec[pivot_B];
        bvec[pivot_B]=bvec[pivot_A];
        bvec[pivot_A]=wrk3;
      }
    }
    for(j=i;j<ndata;j++){
      wrk3=adim[j][i-1] / adim[i-1][i-1];
      for(k=0;k<ndata;k++){
        adim[j][k]-=adim[i-1][k]*wrk3;
      }
      bvec[j]-=bvec[i-1]*wrk3;
    }
  }
  for(i=ndata-1;i>=0;i--){
    if(i==ndata){
      xsol[i]=bvec[i]/adim[i][i];
    }
    if(i!=ndata){
      wrk3=bvec[i];
      for(j=ndata;j>i;j--){
        wrk3-=adim[i][j]*xsol[j];
      }
      xsol[i]=wrk3/adim[i][i];
    }
  }

  return 0;
}