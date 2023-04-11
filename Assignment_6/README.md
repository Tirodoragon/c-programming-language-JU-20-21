# Assignment 6
## Calculating the number π using the Monte Carlo method.
We randomly draw pairs of real numbers (i.e., two ```double``` numbers) from the range [0,1) and treat them as coordinates (x,y) of a point in a square with a side length of 1.

Let N be the number of drawn points (pairs of numbers).

For each point, we check whether it belongs to the interior of the quarter-circle and count the number of hits - let this number be K.

With increasing N, the ratio K/N becomes an increasingly better approximation of the ratio of the area of the quarter-circle to the area of the square.

Be careful with integer division!

From this, calculate the number π.

To generate pseudo-random numbers, use:
* ```r8_uniform_01()``` from Assignment 3
* or appropriately scaled ```rand()``` (which may give worse quality)

You need to draw several hundred thousand points ```Ntot```, where ```N``` increases from 1 to ```Ntot```.

For testing the program, use smaller Ntot.

Output the value of π every so often, e.g., for Ntot = 100*1000; output pi every 1000 draws.

Evaluate the accuracy of the result.

Redirect the output to a file and compare it in gnuplot.

N.B. the constant π is defined in gnuplot.

For the binomial distribution, the $mean = Np$, and the variance is $Np(1-p)$.

Assuming that $Np≈K$, we obtain an estimate of the error on K:

$ΔK = \sqrt{K(1 - \frac{K}{N})}$

Calculate the error on the value of π from this and output it as another "column" for gnuplot.

In gnuplot, create a graph showing the errors, something like:

```plot 'pi.dat' w err, '' w l, pi```

Comment on whether the obtained value is within the expected errors.
