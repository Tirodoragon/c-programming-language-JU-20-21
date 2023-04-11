#include <stdio.h>
#include <math.h>
#define PLIK "rnd.txt"

int r8_seed = 987654321; /* zmieniona wartosc r8_seed jako dowod porownania wynikow dla kilku wartosci r8_seed */

double r8_uniform_01() {
    const int i4_huge = 0x7FFFFFFF;
    const int i1 = 127773;

    r8_seed = 16807 * (r8_seed % i1) - r8_seed / i1 * 2836;
    if (r8_seed < 0) r8_seed += i4_huge;
    return r8_seed * 4.656612875e-10;
}

double r8_normal_01() {
    return sqrt(-2.0 * log(r8_uniform_01())) * cos(2.0 * M_PI * r8_uniform_01());
}

double RandNormal(double avg, double std_dev) {
    return std_dev*r8_normal_01() + avg;
}

int main() {
    double avg, std_dev = 0;
    printf("Podaj srednia, jakiej chcesz uzyc do wygenerowania danych (losowe liczby wg. rozkladu normalnego): ");
    scanf("%lf", &avg);
    printf("Podaj odchylenie standardowe, jak wyzej: ");
    scanf("%lf", &std_dev);
    FILE *plik;
    plik = fopen(PLIK, "w");
    for(int i = 1; i <= 10000; i++)
    fprintf(plik, "%lf\n", RandNormal(avg, std_dev));
    fclose(plik);
    return 0;
}