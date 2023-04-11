#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::stod;

double odch1(int N, double tab[], double sred);
int main() {
    double val, sum = 0;
    int N = 0;
    double tab[10000];
    string wiersz;
    std::string::size_type sz;
    ifstream plik ("rnd.txt");
    if (plik.is_open())
    {
	while(! plik.eof())
	{
	    getline (plik, wiersz);
	    val = stod(wiersz, &sz);
	    tab[N] = val;
	    sum += val;
	    N++;
        }
	plik.close();
    }
    else cout << "Blad przy otwieraniu pliku" << endl;
    cout << "N = " << N
	<< "\nSuma = " << sum << endl;
    double sred = sum / N;
    cout << "Srednia = " << sred << endl;
    double odch2 = odch1(N, tab, sred);
    double odch = sqrt(odch2 / N);
    cout << "Odchylenie standardowe = " << odch << endl;
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