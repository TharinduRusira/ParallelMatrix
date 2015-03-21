#include <iostream>
#include <stdlib.h>
#include <math.h>

#define N 10

using namespace std;

float** rand_mat_gen(size_t n)
{
  float **mat =  (float**)malloc(N*sizeof(float*));
	int i,j;
	srand(time(NULL)); // seed the pseudo-random generator
	for(i=0;i<n;i++){
		mat[i] = (float*)malloc(n*sizeof(float));
		for(j=0;j<n;j++){
			int number = rand();
			mat[i][j] = (float)number/(float)pow((double)10,(number%10));
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
	return mat;
}


int main(int argc, char **argv) {
    
    return 0;
}
