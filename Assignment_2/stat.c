#include <stdio.h>
#include <math.h>

int main() {
    double val, sum, sum_sqr = 0;
    int N = 0;

    printf("Wprowadz liczby oddzielajac je enterem.\nAby przestac wprowadzac liczby napisz dowolny znak, ktory nie jest liczba:\n");
    while(scanf("%lf", &val) == 1) {
	sum += val;
	sum_sqr += val * val;
	N++;
    }

    printf("N = %d\n", N);
    printf("Suma = %g\n", sum);

    double avg = sum / N;
    printf("Srednia = %g\n", avg);

    double dev = sqrt(((N * sum_sqr) - (sum * sum))) / N;
    printf("Odchylenie standardowe = %g\n", dev);

    return 0;
}