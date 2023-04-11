# Assignment 3
## Pseudo-random number generator according to the normal distribution.
Write a program called "normgen" that outputs N pseudo-random numbers according to the normal distribution on the standard output.

Tips:
* N should be an integer variable defined in the main function, e.g.
    ```c
    int N = 10;
    ```
* Download the rand_normal.h and rand_normal.c files from the course page and save them in the "assignment" folder (where the normgen.c file is located).
* Use the main module example rand1.c from the course page.
* Choose your own values for the mu and sigma variables.
* Only numbers should appear on the standard output - no other texts, such as "enter ...".

Test version:
* To test the program, use a small N value, such as 10.
* Examine the generated numbers and evaluate whether they appear consistent with the chosen mu and sigma values.

Final version:
* Use a large N value, such as 10000.
* Run the program by redirecting the output to a file (e.g., rnd.txt):
    * ./normgen > rnd.txt (Linux)
    * normgen.exe > rnd.txt (Windows)
* Examine the rnd.txt file to ensure it appears correct.

## Results analysis
Here, we will use the "stat" program from Assignment 2.

Run "stat < rnd.txt" and compare how the output values of the mean and standard deviation match with the values used to generate the data in the normgen program.

You can also run "stat < rnd.txt > stat.out" and then view the stat.out file.

For 5.0:
* Compare the results for several values of the r8_seed variable."
