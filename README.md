-> # Exploiting hardware parallelization to optimize Matrix Multiplication problem <-
-> ## Tharindu Rusira, Chalitha Perera <-
-> ### Department of Computer Science and Engineering <-
-> ### University of Moratuwa <-
-> ### Sri Lanka <-
<br /> <br />
## Compiling the code

This project uses Cmake utility to compile the code and build necessary libraries. 
Navigate to lab4/build directory and run "make".
  
  ~/Lab4/build make

If everything goes well, an executable file with the name "lab4" will be generated.
  
  [ 50%] Built target lab4_lib
  
  [100%] Built target lab4


## Executing Compiled Program

In order to run compiled code you need to give arguments
matrix multiplication version and the dimension of the square matrix.

### Running Serial Version with dimension 1000
  
  ./lab4 serial 1000

### Running Parallel Version with dimension 1000
  
  ./lab4 parallel 1000

### Running Optimized Version with dimension 1000
  
  ./lab4 optmized 1000

### Determing Number of iterations to get runtimes within an accuracy of ±5% and 95% confidence level
use lab4_stats.py script

example
------------
  
  python lab4_stats.py --run_command="./lab4 parallel 1000" with execute matrix multiplication with

 default of 5 iterations and give average, standard deviation and required number of iterations

then again run with n iterations to get the average
  
  python lab4_stats.py --run_command="./lab4 parallel 1000" --iterations=n
