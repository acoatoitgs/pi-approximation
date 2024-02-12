# Pi approximations

This is a collection of algorithms whose objective is to compute pi (π) to high precision.

1. ### Montecarlo method
This method is based on randomness. The idea is to generate points randomly in a square with an inscribed circle in it. Naming $I$ the points which are inside the circle, and $T$ the total number of points, we can estimate that:

$$ \frac{I}{T} \approx \frac{\pi}{4}$$

Compile the program with:

`g++ montecarlo.cpp -o montecarlo`
