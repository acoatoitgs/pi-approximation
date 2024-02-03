#include <iostream>
#include <random>
#include <iomanip>

long double pi;

int main()
{
    std::cout << std::setprecision(13);
    long long countInside = 0;
    long long countOutside = 0;

    std::mt19937 mt(time(nullptr));

    long long centerX = mt.max() / 2;
    long long centerY = mt.max() / 2;
    long long radius = mt.max() / 2;

    long long radSquare = radius * radius;

    std::cout << "Insert number of cycles: \n";
    long long cycles = 1000000000;
    long long completedCycles = 0;

    while (cycles > 0)
    {
        for (int i = 0; i < std::min(100000000ll, cycles); i++)
        {
            long long simX = mt();
            long long simY = mt();

            long long distance = (simX - centerX) * (simX - centerX) + (simY - centerY) * (simY - centerY);

            distance <= radSquare ? countInside++ : countOutside++;
        }

        completedCycles += std::min(100000000ll, cycles);
        cycles -= 100000000ll;

        pi = 4 * ((long double)countInside / (long double)completedCycles);
        std::cout << "Simulated " << completedCycles << " cycles, pi = " << pi << "\n";
    }
}