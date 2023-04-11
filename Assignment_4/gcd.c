#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int NWD(int a, int b) {
    if(a < 1 || b < 1)
    return 0;
    else {
	while(a != b) {
	    if (a < b)
		b -= a;
	    else
		a -= b;
	}
    }
    return a;
}

int main(int argc, char* argv[]) {
    int a = 0, b = 0, x = 0;
    if(argc == 1) {
	printf("Wpisuj po dwie liczby, w razie pojawienia sie bledu wpisz je ponownie:\n");
	printf("W celu zakonczenia wpisywania wpisz znak niebedacy liczba\n");
	while(scanf("%d %d", &a, &b) == 2) {
	    x = NWD(a, b);
	    if(x == 0)
		printf("Bledne dane\n");
	    else
		printf("NWD = %d\n", x);
	}
    }
    else if(argc == 2) {
	if(strcmp(argv[1], "-q") == 0) {
	    while(scanf("%d %d", &a, &b) == 2) {
		printf("%d\n", NWD(a, b));
	    }
	}
	else 
	    printf("Prosze podac druga liczbe\n");
    }
    else if(argc == 3) {
	printf("NWD = %d\n", NWD(atoi(argv[1]), atoi(argv[2])));
    }
    else printf("Za duzo argumentow\n");
    return 0;
}