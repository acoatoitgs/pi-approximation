# Pi approximations

This is a collection of algorithms whose objective is to compute pi (π) to high precision.

1. ### Montecarlo method
This method is based on randomness. The idea is to generate points randomly in a square with an inscribed circle in it. Naming $I$ the points which are inside the circle, and $T$ the total number of points, we get that:  $\frac{\pi}{4} \approx \frac{I}{T}$

This method works for up to 4 decimal places. After that, it becomes slow and inaccurate. There are much better methods listed here.
Compile the program with:
`g++ montecarlo.cpp -o montecarlo`

2. ### Madhava-Leibniz

This approach is based on the Madhava-Leibniz convergent series:

$$\pi = 4\sum_{n=0}^{\infty}\frac{(-1)^n}{2n+1}$$

It's able to compute pi up to 9 decimal places in about 10s. This is already a pretty good result and it goes beyond any practical use.

Compile the program with:
`g++ madhava_leibniz.cpp -o madhava_leibniz`

3. ### Borweins

a  