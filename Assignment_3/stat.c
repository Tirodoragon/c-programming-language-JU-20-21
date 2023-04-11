#include <stdio.h>
#include <math.h>
#define PLIK "rnd.txt"

double odch1(int N, double tab[], double sred);
int main() {
    double val, sum = 0;
    int N = 0;
    double tab[10000];
    FILE *plik;
    plik = fopen(PLIK, "r");
    while(fscanf(plik, "%lf", &val) == 1) {
	tab[N] = val;
        sum += val;
        N++;
    }
    printf("N = %d\n", N);
    printf("Suma = %g\n", sum);
    double sred = sum / N;
    printf("Srednia = %g\n", sred);
    double odch2 = odch1(N, tab, sred);
    double odch = sqrt(odch2 / N);
    printf("Odchylenie standardowe = %g\n", odch);
    return 0;
}

double odch1(int N, double tab[], double sred)
{
    double sklad = 0;
    double odch1 = 0;
    while(N > 0) {
        sklad = pow(tab[N - 1] - sred, 2);
        odch1 = odch1 + sklad;
        N--;
    }
    return odch1;
}