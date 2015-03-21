#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "mat_utils.h"

#define N 10

using namespace std;

double** rand_mat_gen(size_t n)
{
  double **mat =  (double**)malloc(N*sizeof(double*));
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


int main(int argc, char **argv) {
    rand_mat_gen(5);
    return 0;
}
