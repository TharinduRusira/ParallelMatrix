double** mat_mul_simple(size_t N, double** A,double** B)
{
  double** c = (double**)malloc(N*sizeof(double*));
  
  double** matA = A;
  double** matB = B;
  clock_t start = clock();
  
  for(int i=0;i<N;i++)
  {
    c[i] = (double*)malloc(M1*sizeof(double));
    for(int j=0;j<M1;j++)
    {
	c[i][j]=0;
	for(int k=0;k<M2;k++)
	{
	  c[i][j]+= matA[i][k]*matB[k][j];
	}
    }
  }
  cout << "Time Taken for matvec_simple= " <<clock() - start<<endl;
  return c;
  
}