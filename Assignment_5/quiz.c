/* Pomiar za pomoca time nie jest obarczony bledem 1s!!! */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int Nmin_number = 2;
const int Nmax_number = 9;

const int Nmin_operation = 1;
const int Nmax_operation = 4;

int RandLtd(int imin, int imax) {
    return rand() % (imax + 1 - imin) + imin;
}

int main() {
    srand(time(NULL));

    printf("Czas na odpowiedz wynosi 4s\n\n");

    int a = 0;
    int b = 0;

    int result_user = 0;
    int result_correct = 0;

    time_t time_start = 0;
    time_t time_end = 0;

    int time_used = 0;
    int time_limit = 4;

    int correct_count = 0;

    int op = 0;
    for (int i = 0; i < 10; i++) {
	op = RandLtd(Nmin_operation, Nmax_operation);
	switch(op)
	{
	    case 1:
    		a = RandLtd(Nmin_number, Nmax_number);
    		b = RandLtd(Nmin_number, Nmax_number);
    	        printf("Podaj wynik %d * %d = ", a, b);

	        time(&time_start);
    	        scanf("%d", &result_user);
	        time(&time_end);
	        time_used = time_end - time_start;
	        printf("\nCzas udzielenia odpowiedzi: %ds\n", time_used);

    		result_correct = a * b;
    		if(result_user == result_correct && time_used <= time_limit) {
		    printf("Poprawny wynik\n\n");
		    correct_count++;
	        }
		else if(time_used > time_limit)
		    printf("Przekroczono limit czasu\n\n");
	        else
		    printf("Niepoprawny wynik\n\n");
		break;

	    case 2:
		a = RandLtd(Nmin_number, Nmax_number);
		b = RandLtd(Nmin_number, Nmax_number);
		printf("Podaj wynik %d + %d = ", a, b);

		time(&time_start);
		scanf("%d", &result_user);
		time(&time_end);
		time_used = time_end - time_start;
		printf("\nCzas udzielenia odpowiedzi: %ds\n", time_used);

		result_correct = a + b;
		if(result_user == result_correct && time_used <= time_limit) {
		    printf("Poprawny wynik\n\n");
		    correct_count++;
		}
		else if(time_used > time_limit)
		    printf("Przekroczono limit czasu\n\n");
		else
		    printf("Niepoprawny wynik\n\n");
		break;

	    case 3:
		a = RandLtd(Nmin_number, Nmax_number);
		b = RandLtd(Nmin_number, Nmax_number);
		printf("Podaj wynik %d / %d = ", a*b, b);

		time(&time_start);
		scanf("%d", &result_user);
		time(&time_end);
		time_used = time_end - time_start;
		printf("\nCzas udzielenia odpowiedzi: %ds\n", time_used);

		result_correct = a*b / b;
		if (result_user == result_correct && time_used <= time_limit) {
		    printf("Poprawny wynik\n\n");
		    correct_count++;
		}
		else if(time_used > time_limit)
		    printf("Przekroczono limit czasu\n\n");
		else
		    printf("Niepoprawny wynik\n\n");
		break;

	    case 4:
		a = RandLtd(Nmin_number, Nmax_number);
		b = RandLtd(Nmin_number, Nmax_number);
		while(a == b) {
		    a = RandLtd(Nmin_number, Nmax_number);
		    b = RandLtd(Nmin_number, Nmax_number);
		}
		if(a > b)
		    printf("Podaj wynik %d - %d = ", a, b);
		if(a < b)
		    printf("Podaj wynik %d - %d = ", b, a);
		
		time(&time_start);
		scanf("%d", &result_user);
		time(&time_end);
		time_used = time_end - time_start;
		printf("\nCzas udzielania odpowiedzi: %ds\n", time_used);

		if(a > b)
		    result_correct = a - b;
		if(a < b)
		    result_correct = b - a;
		if(result_user == result_correct && time_used <= time_limit) {
		    printf("Poprawny wynik\n\n");
		    correct_count++;
		}
		else if(time_used > time_limit)
		    printf("Przekroczono limit czasu\n\n");
		else
		    printf("Niepoprawny wynik\n\n");
		break;

	    default:
		printf("Error\n");
		break;
	}
    }

    int percentage_correct = correct_count * 10;
    printf("Procent poprawnych odpowiedzi: %d%%\n", percentage_correct);

    return 0;
}