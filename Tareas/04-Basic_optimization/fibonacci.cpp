#include <iostream>
#include <chrono>

// Naive recursive Fibonacci
long long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

long long fib_fast(int n){
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(int argc, char **argv) {
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);
    int n = atoi(argv[1]);
    auto start = std::chrono::high_resolution_clock::now();

    long long result = fib(n);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    start = std::chrono::high_resolution_clock::now();

    long long result_fast = fib_fast(n);

    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_fast = end - start;

    std::cout << n << "\t" << elapsed.count()/4.3e-05 << "\t" << elapsed_fast.count()/8.1e-08 << "\n";

    return 0;
}