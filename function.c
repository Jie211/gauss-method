#include "header.h"

int getmatrix(const char *file, double **a, int ndata)
{
  FILE *matrix;
  int i, j;
  double val;

  if((matrix = fopen(file, "r")) == NULL){
    printf("%s file open error\n", file);
    return 1;
  }

  for(i = 0;i<ndata;i++)
    for(j = 0;j<ndata;j++)
      a[i][j] = 0.0;

  for(i=0;i<ndata;i++){
    for(j=0;j<ndata;j++){
      fscanf(matrix, "%lf", &val);
      a[i][j] = val;
    }
  }

  fclose(matrix);
  return 0;
}

int getvector(const char *file, double *v, int ndata)
{
  FILE *vector;
  int i;
  double val;

  if((vector = fopen(file, "r")) == NULL){
    printf("%s file open error\n", file);
    return 1;
  }

  for(i = 0;i<ndata;i++)
    v[i] = 0.0;

  for(i = 0;i<ndata;i++)
  {
    fscanf(vector, "%lf", &val);
    v[i] = val;
  }

  fclose(vector);
  return 0;
}