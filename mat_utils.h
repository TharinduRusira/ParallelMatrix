#ifndef MAT_UTILS_H
#define MAT_UTILS_H

double** rand_mat_gen(size_t n);
double** mat_mul_simple(size_t N, double** A,double** B);
double** mat_mut_parallel(size_t N,double** A,double** B);
double** mat_mul_opt_transpose(size_t N,double** A,double** B);
void print_mat(size_t N,double** A);
#endif
