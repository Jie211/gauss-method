#include "header.h"

int main(int argc, char const* argv[])
{
  int ndata=3;//matrix size
  int i, j;
  double **adim, **wrk1;
  double *xsol, *bvec, *wrk2;

  if(argc!=3){
    printf("Usage:\n");
    printf("./Sovler matrix.txt bvec.txt\n");
    exit(0);
  }

  xsol=(double *)malloc(sizeof(double)*ndata);
  bvec=(double *)malloc(sizeof(double)*ndata);
  wrk2=(double *)malloc(sizeof(double)*ndata);

  adim=(double **)malloc(sizeof(double *)*ndata);
  wrk1=(double **)malloc(sizeof(double *)*ndata);
  for(i=0;i<ndata;i++){
    adim[i]=(double *)malloc(sizeof(double)*ndata);
    wrk1[i]=(double *)malloc(sizeof(double)*ndata);
  }


  if(getmatrix(argv[1], adim, ndata)==1){
    printf("getmatrix error\n");
    return 1;
  }
  if(getvector(argv[2], bvec, ndata)==1){
    printf("getvector error\n");
    return 1;
  }

  for(i=0;i<ndata;i++){
    wrk2[i]=0.0;
    xsol[i]=0.0;
    for(j=0;j<ndata;j++){
      wrk1[i][j]=0.0;
    }
  }

  //print matrix
  printf("matirx=\n");
  for(i=0;i<ndata;i++){
    for(j=0;j<ndata;j++){
      printf("%f ", adim[i][j]);
    }
    putchar('\n');
  }
  printf("bvec=\n");
  for(i=0;i<ndata;i++){
    printf("%f\n", bvec[i]);
  }

  if(gauss(adim, xsol, bvec, 10, ndata, wrk1, wrk2)==1){
    printf("pivot error\n");
    return 1;
  }

  //print output xvec
  printf("------------------------\n");
  printf("x=\n");
  for(i=0;i<ndata;i++){
    printf("%f\n", xsol[i]);
  }

  free(xsol);
  free(bvec);
  free(wrk2);
  for(i=0;i<ndata;i++){
    free(adim[i]);
    free(wrk1[i]);
  }
  free(adim);
  free(wrk1);

  return 0;
}
