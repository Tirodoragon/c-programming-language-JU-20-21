#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::setprecision;
using std::endl;

int main() {
    for(int n = 5; n < 20; n = n + 2) {
	cout << setprecision(n) << M_PI << ", " << M_PI*M_PI << endl;
    }
    return 0;
}