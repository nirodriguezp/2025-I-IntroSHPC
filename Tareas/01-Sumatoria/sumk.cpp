#include <iostream>
#include <cmath>

typedef float REAL;

REAL sum1(int k);
REAL sum2(int k);

int main(void)
{
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    int N = 1000000;
    REAL s1 = 0.0, s2 = 0.0;

    for (int k = 1; k <= N; k++)
    {
        s1 = sum1(k);
        s2 = sum2(k);
        std::cout << k << "\t" << s1 << "\t" << s2 << "\t" << std::fabs(1-(s1/s2)) << "\n";
    }
    return 0;
}

REAL sum1(int k)
{
    REAL suma1 = 0.0;
    for(int i = 1; i <= k; i++)
    {
        suma1 += 1.0/i;
    }

    return suma1;
}

REAL sum2(int k)
{
    REAL suma2 = 0.0;
    for(int i = k; i >= 1; i--)
    {
        suma2 += 1.0/i;
    }

    return suma2;
}