// imprima los numeros del 1 al 10 usando while
#include <iostream> 

// declaration
void print_numbers(int nmax);

int main(void) 
{
    print_numbers(3000000000);

  return 0;
}

// implementation
void print_numbers(int nmax)
{
  std::cout << nmax << std::endl;  
  for (int n = 1; n <= nmax; n++) {
    std::cout << n << std::endl;
  } 
}