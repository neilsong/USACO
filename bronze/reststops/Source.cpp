#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(void) {
	ifstream fin("reststops.in");
	ofstream fout("reststops.out");

	vector <int> trail;

	double a, b, vf, vb;
	cin >> a >> b >> vf >> vb;

	trail.resize(a+1);

	for (int i = 0; i < b; i++) {
		int A, b;
		cin >> A >> b;
		trail[A] = b;
	}

	double Q = 0;
	double M = 0;
	int tasty = 0;

	for (int i = 1; i <= a * vb; i++) {
		M += 1 /vb;
		Q += 1 / vf;
		if (ceil(M) == Q && M > Q && trail[M] > 0) {
			b -= 1 / vb;
			tasty += trail[M];
		}
	}

	cout << tasty << endl;

	return 0;
}