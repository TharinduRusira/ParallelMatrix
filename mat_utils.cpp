#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

using namespace std;
using namespace std::chrono;

const int NUM_THREADS = 4;

double** rand_mat_gen(size_t n)
{
  double **mat =  (double**)malloc(n*sizeof(double*));
  int i,j;
  //srand(time(NULL)); // seed the pseudo-random generator
  for(i=0;i<n;i++){
    mat[i] = (double*)malloc(n*sizeof(double));
    for(j=0;j<n;j++){
      int number = rand()%1000;
      //mat[i][j] = number/pow((double)10,(number%10));
      mat[i][j] = number;
    }
  }
  return mat;
}


double** mat_mul_simple(size_t n, double** A,double** B)
{
  double** c = (double**)malloc(n*sizeof(double*));
  for(int i=0;i<n;i++)
  {
    c[i] = (double*)malloc(n*sizeof(double));
  }
  double** matA = A;
  double** matB = B;
  high_resolution_clock::time_point start = high_resolution_clock::now();
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
	c[i][j]=0;
	for(int k=0;k<n;k++)
	{
	  c[i][j]+= matA[i][k]*matB[k][j];
	}
    }
  }
  high_resolution_clock::time_point end = high_resolution_clock::now();
  double elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>( end-start).count();
  cout << "Elapsed time = " << elapsed_time/1000 << " miliseconds";
  return c;
  
}

double** mat_mut_parallel(size_t N, double** A, double** B)
{
  double** C = (double**)malloc(N*sizeof(double*));
  for(int i=0;i<N;i++)
  {
    C[i] = (double*)malloc(N*sizeof(double));
  }  
  int i,j,k;
  
  high_resolution_clock::time_point start = high_resolution_clock::now();

 #pragma omp parallel for num_threads(NUM_THREADS) default(none) shared(A,B,C,N) private(i,j,k)
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
	C[i][j]=0;
	for(k=0;k<N;k++)
	{
	  C[i][j]+= A[i][k]*B[k][j];
	}
    }
  }
  high_resolution_clock::time_point end = high_resolution_clock::now();
  double elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>( end-start).count();
  cout << "Elapsed time = " << elapsed_time/1000 << " miliseconds";
  return C;
}

double** mat_mul_opt_transpose(size_t N, double** A, double** B)
{
  int i,j,k;
  double** C = (double**)malloc(N*sizeof(double*));
  for(i=0;i<N;i++)
  {
    C[i] = (double*)malloc(N*sizeof(double));
  }

  double** B_t = (double**)malloc(N*sizeof(double*));
  for(i=0;i<N;i++){
    B_t[i] = (double*)malloc(N*sizeof(double)); 
  }
    
  high_resolution_clock::time_point start = high_resolution_clock::now();
  
 #pragma omp parallel for num_threads(NUM_THREADS) shared(B,B_t) private(i,j)
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
     B_t[i][j] = B[j][i]; 
    }
  }
 #pragma omp parallel for num_threads(NUM_THREADS) default(none) shared(A,B_t,C,N) private(i,j,k)
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
	C[i][j]=0;
	for(k=0;k<N;k++)
	{
	  C[i][j]+= A[i][k]*B_t[j][k];
	}
    }
  }
  high_resolution_clock::time_point end = high_resolution_clock::now();
  double elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>( end-start).count();
  cout << "Elapsed time = " << elapsed_time/1000 << " miliseconds";
  return C;
}

void print_mat(size_t N, double** A)
{
  for(int i=0; i<N; i++){
   for(int j=0; j<N; j++){
     cout << A[i][j] << "\t";
   }
   cout << endl;
  }
}


