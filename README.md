# Pi approximations

This is a collection of algorithms whose objective is to compute pi (π) to high precision.
I aim to further expand this list with some other algorithms in the future.

1. ### Montecarlo method
This method is based on randomness. The idea is to generate 2D points randomly in a square with an inscribed circle in it. Let $I$ be the number of points inside the circle, and $T$ the total number of points, we get that:

$$\frac{\pi}{4} \approx \frac{I}{T}$$

This method works for up to 4 decimal places. After that, it becomes slow and inaccurate. There are much better methods listed here.
Compile the program with:
`g++ montecarlo.cpp -o montecarlo`

2. ### Madhava-Leibniz series

This approach is based on the Madhava-Leibniz convergent series:

$$\pi = 4\sum_{n=0}^{\infty}\frac{(-1)^n}{2n+1}$$

It's able to compute π up to 9 decimal places in about 10 seconds. This is already a pretty good result and it goes beyond any practical use.

Compile the program with:
`g++ madhava_leibniz.cpp -o madhava_leibniz`

3. ### Borwein's algorithm

This is the best algorithm listed here. It was discovered in 1985 by Jonathan and Peter Borwein. It's an iterative approach that is able to give over a trillion correct digits after only 20 iterations. The given code computes the first million digits in about a second.

$$y_0 = \sqrt{2}-1, a_0 = 6-4\sqrt{2}$$

$$f(y) = (1-y^4)^{\frac{1}{4}}$$

$$y_{k+1} = \frac{1-f(y_k)}{1+f(y_k)}$$

$$a_{k+1} = a_{k}(1+y_{k+1})^4-2^{2k+3}y_{k+1}(1+y_{k+1}+y_{k+1}^2)$$

$$\pi \approx \frac{1}{a_k}$$

Compile the program with:
`gcc borweins.c -o borweins -lmpfr`