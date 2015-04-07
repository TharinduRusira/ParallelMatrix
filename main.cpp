#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <chrono>

#include "mat_utils.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {
  
    string run_version = argv[1];
    int mat_dim = strtol(argv[2], NULL, 10);
    cout << "Running " << run_version << " version with matrix dimension " << mat_dim;  
    cout << endl;
    double** rand_mat_A = rand_mat_gen(mat_dim);
    double** rand_mat_B = rand_mat_gen(mat_dim);

    if(run_version == "serial"){
      mat_mul_simple(mat_dim,rand_mat_A,rand_mat_B);
    }
    else if(run_version == "parallel"){
      mat_mut_parallel(mat_dim, rand_mat_A, rand_mat_B);
    }
    else if(run_version == "optimized"){
      mat_mul_opt_transpose(mat_dim,rand_mat_A,rand_mat_B);
    }
    else if(run_version == "test_correctness"){
      cout << "Matrix A" << endl;
      print_mat(mat_dim, rand_mat_A);
      cout << endl;
      
      cout << "Matrix B" << endl;
      print_mat(mat_dim, rand_mat_B);
      cout << endl;
      
      cout << "Serial Output" << endl;
      double** mat = mat_mul_simple(mat_dim,rand_mat_A,rand_mat_B);
      cout << endl;
      print_mat(mat_dim, mat);
      cout << endl;
      
      cout << "Parallel Output" << endl;
      mat = mat_mut_parallel(mat_dim,rand_mat_A,rand_mat_B);
      cout << endl;
      print_mat(mat_dim, mat);
      cout << endl;
      
      cout << "Optmized Output" << endl;
      mat = mat_mul_opt_transpose(mat_dim,rand_mat_A,rand_mat_B);
      cout << endl;
      print_mat(mat_dim, mat);
      cout << endl;
    }
    cout << endl;  
    return 0;
}


