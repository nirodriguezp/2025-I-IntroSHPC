#include <iostream>
#include <cstdlib>

typedef float REAL;

int main(int argc, char **argv)
{   
  std::cout.precision(20);
  std::cout.setf(std::ios::scientific);
  int N = std::atoi(argv[1]);
  REAL one=1.0, eps=1.0;

    for(int i=1; i<=N; i++){

        eps /= 2.0;
        one = 1.0 + eps;
        std::cout << i << "\t" << one << "\t" << eps << "\n";

    }
    return 0;
    

}