#include <iostream>
#include <random>
#include <iomanip>

int main()
{
    std::cout << std::setprecision(17);
    long double aprox = 1;

    for (long long i = 3; i < 10000000000; i += 2)
    {
        aprox += (i & 2) ? -1.0 / (long double)i : 1.0 / (long double)i;
    }

    long double pi = 4 * aprox;

    std::cout << "pi = " << pi << "\n";
}