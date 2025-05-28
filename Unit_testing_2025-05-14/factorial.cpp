#include "factorial.h"
#include <iostream>

long factorial(int number)
{
    if (number == 0) return 1;
    if (number < 0){
        std::cerr << "Negative numbers not allowed. Returning -1.\n";
        return -1;
    }
    return number < 0 ? number : factorial(number-1)*number;
}