#include <iostream>
#include <cmath>

typedef float REAL;

REAL sumk(int k);

int main(void)
{
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    for (int k = 1; k <= 1000; k++)
    {
    std::cout << k << "\t" << sumk(k) << "\n";
    }
    return 0;
}

REAL sumk(int k)
{
    REAL suma = 0.0;
    for(int i = 1; i <= k; i++)
    {
        suma += 0.1;
    }
    REAL aux = k/10.0;
    return std::fabs(aux - suma);
}