# Assignment 4
## Greatest Common Divisior (GCD).
Write a function:
```c
int GCD(int a, int b)
```
which calculates it using the Euclidean algorithm.

For a > 1 or b < 1, the GCD function should return 0.

Version 1:
* Read the values of arguments a and b in the main function using scanf.
* Read "in a loop" until "non-number" is entered - just like in the stat program.

Version 2:
* Read the arguments from the command line.

Let's call our program gcd.

It should work as follows:
* ```gcd``` - works like Version 1
* ```gcd 91 65``` - works like Version 1 for a=91, b=65 and does not ask for additional a, b
* ```gcd 91``` - displays an error message: when a is provided, b must also be provided
