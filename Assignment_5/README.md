# Assignment 5
## Operation table quiz
The program queries from the "operation table".

It asks 10 questions and counts the number of correct answers.

At the end, it displays the result as a percentage of correct answers.

For each question, two natural numbers are randomly generated from the range of ```Nmin``` to ```Nmax```.

Write a function ```RandLtd(int imin, int imax)``` that returns random numbers from the specified range [imin, imax].

Figure out how to do this using the standard ```rand``` function.

Limit the response time to ```time_limit``` - e.g. 4 seconds.

Randomly select the type of operation: ```*, +, / -```.

It is good to think about how to prepare the data for subtraction and division, so that the result is in the range [Nmin, Nmax].
