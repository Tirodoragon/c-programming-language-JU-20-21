#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

int main() {
    double val, sum, sum_sqr = 0;
    int N = 0;

    cout << "Wprowadz liczby oddzielajac je enterem.\nAby przestac wprowadzac liczby napisz dowolny znak, ktory nie jest liczba:\n";
    while(cin >> val) {
        sum += val;
        sum_sqr += val * val;
        N++;
    }

    cout << "N = " << N
	<< "\nSuma = " << sum << "\n";

    double avg = sum / N;
    cout << "Srednia = " << avg << "\n";

    double dev = sqrt(((N * sum_sqr) - (sum * sum))) / N;
    cout << "Odchylenie standardowe = " << dev << "\n";

    return 0;
}