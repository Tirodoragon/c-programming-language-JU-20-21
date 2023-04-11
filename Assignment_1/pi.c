#include <stdio.h>
#include <math.h>

int main() {
    for(int n = 4; n < 20; n = n + 2)
    printf("%.*lf, %.*lf \n", n, M_PI, n, M_PI*M_PI);
    return 0;
}
