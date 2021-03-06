#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

long long countp = 0;


void findo(string c, int b) {
	countp += count(c.begin() + b, c.end(), 'W');

}
void findc(string c, int b) {
	size_t f = c.find("O", b);
	if (f != string::npos) {
		findo(c, f);
		findc(c, f+1);
	}
	else {
		return;
	}
}

void findf(string c, int b) {
	size_t f = c.find("C", b + 1);
	if (f != string::npos) {
		findc(c, f);
		findf(c, f);
	}
	else {
		return;
	}
}





int main(void)
{
	
	ifstream fin("cow.in");
	ofstream fout("cow.out");

	int b;
	fin >> b;
	string a;
	fin >> a;
	findf(a, -1);

	fout << countp << endl;

	return 0;
}