#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

struct Vector_t {
    double x, y;
};

Vector_t Sum(const Vector_t& a, const Vector_t& b) {
    Vector_t c;
	
    c.x = a.x + b.x;
    c.y = a.y + b.y;
	
    return c;
}

Vector_t Diff(const Vector_t& a, const Vector_t& b) {
    Vector_t c;
	
    c.x = a.x - b.x;
    c.y = a.y - b.y;
	
    return c;
}

double Sprod(const Vector_t& a, const Vector_t& b) {
    double c;
	
    c = a.x * b.x + a.y * b.y;
	
    return c;
}

double Length(const Vector_t& a) {
    double c;
	
    c = sqrt(pow(a.x, 2) + pow(a.y, 2));
	
    return c;
}

double Dist(const Vector_t& a, const Vector_t& b) {
    double c;
	
    c = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	
    return c;
}

double Vprod(const Vector_t& a, const Vector_t& b) {
    double c;
	
    c = a.x * b.y - a.y * b.x;
	
    return c;
}

void MakePlot(const vector<Vector_t>& vec) {
    fstream file("vec.gpl", ios::out);

    if(file.good()) {
	file << "set size ratio -1\n";
	file << "set grid\n";
	file << "unset key\n";
	file << "$D << EOD\n";

	for(int i = 0; i < (int) vec.size(); i++) {
	    file << vec[i].x << " " << vec[i].y << '\n';
	}
	
	file << vec[0].x << " " << vec[0].y << '\n';
	file << "EOD\n";
	file << "plot $D w lp lc 'blue' lw 2 pt 7 ps 1.5\n";

	file.close();
    }
}

double Perimeter(const vector<Vector_t>& vec) {
    double c = 0;

    for(int i = 0; i < (int) vec.size() - 1; i++) {
	c += Dist(vec[i], vec[i + 1]);
    }

    c += Dist(vec[vec.size() - 1], vec[0]);

    return c;
}

double Area(const vector<Vector_t>& vec) {
    double c = 0;

    for(int i = 0; i < (int) vec.size(); i++) {
	c += Vprod(vec[i], vec[(i + 1) % (int) vec.size()]);
    }

    return c * 0.5;
}

int main(int argc, char* argv []) {
    vector<Vector_t> V;
	
    Vector_t v;
	
	fstream input;
	input.open(argv[1]);
    while(input >> v.x >> v.y) {
		V.push_back(v);
    }
	
    cout << Length(V[0]) << '\n';
	
	v = Sum(V[0], V[1]);
	cout << v.x << " " << v.y << '\n';
	
	cout
	<< Dist(V[1], V[2]) << '\n'
	<< Sprod(V[0], V[1]) << '\n'
	<< Vprod(V[0], V[1]) << '\n'
	<< Perimeter(V) << '\n'
	<< Area(V) << '\n';

    input.close();

    MakePlot(V);

    return 0;
}