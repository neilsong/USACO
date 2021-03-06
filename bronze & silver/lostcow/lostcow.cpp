#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

bool isBetween(int a, int c, int b) {
	if (a <= b && c >= b) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(void)
{

	ofstream fout("lostcow.out");
	ifstream fin("lostcow.in");

	int j, b;
	fin >> j >> b;

	int i = 1;

	int count = 0;
	

	int a = j;

	while (true) {
		int c = j + i;
		bool l = 0;
		if (c > a) {
			l = isBetween(a, c, b);
		}
		else if (c <= a) {
			l = isBetween(c, a, b);
		}

		if (l) {
			count += abs(a - b);
			break;
		}
		else {
			count += abs(a - c);
		}

		a = c;

		i *= -2;
	}

	fout << count << endl;

	return 0;
}