#include <stdio.h>
#include <math.h>
#define PLIK "pi.dat"

int r8_seed = 123456789;

double r8_uniform_01() {
    const int i4_huge = 0x7FFFFFFF;
    const int i1 = 127773;

    r8_seed = 16807 * (r8_seed % i1) - r8_seed / i1 * 2836;
    if (r8_seed < 0) r8_seed += i4_huge;
    return r8_seed * 4.656612875e-10;
}

int main() {
    int N = 0, K = 0, count = 1000000, Ntot = 500 * count;
    double x = 0, y = 0, result = 0, err = 0;

    FILE *plik;
    plik = fopen(PLIK, "w");

    for(N = 1; N <= Ntot; N++) {
	x = r8_uniform_01();
	y = r8_uniform_01();

	if((pow(x, 2) + pow(y, 2)) < 1) {
	    K++;
	}

	if(N % count == 0) {
	    result = (double) K / N;
	    err = 4 * sqrt(K * (1 - result)) / N;

	    fprintf(plik, "%g %g\n", result * 4, err);
	}
    }

    fclose(plik);

    return 0;
}