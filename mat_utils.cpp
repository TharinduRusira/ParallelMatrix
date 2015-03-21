#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

double** rand_mat_gen(size_t n)
{
  double **mat =  (double**)malloc(n*sizeof(double*));
	int i,j;
	srand(time(NULL)); // seed the pseudo-random generator
	for(i=0;i<n;i++){
		mat[i] = (double*)malloc(n*sizeof(double));
		for(j=0;j<n;j++){
			int number = rand();
			mat[i][j] = number/pow((double)10,(number%10));
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
	return mat;
}


double** mat_mul_simple(size_t n, double** A,double** B)
{
  double** c = (double**)malloc(n*sizeof(double*));
  
  double** matA = A;
  double** matB = B;
  clock_t start = clock();
  
  for(int i=0;i<n;i++)
  {
    c[i] = (double*)malloc(n*sizeof(double));
    for(int j=0;j<n;j++)
    {
	c[i][j]=0;
	for(int k=0;k<n;k++)
	{
	  c[i][j]+= matA[i][k]*matB[k][j];
	}
    }
  }
  cout << "Time Taken for matvec_simple= " <<clock() - start<<endl;
  return c;
  
}