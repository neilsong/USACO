#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ifstream fin("homework.in");
	ofstream fout("homework.out");

	long n;
	fin >> n;

	vector <double> s;
	vector <pair<double, int>> ks;
	vector <int> z;



	for (int i = 0; i < n; i++) {
		double a;
		fin >> a;
		s.push_back(a);
	}

	double m = min(s[n - 1], s[n - 2]);
	double su = s[n - 1] + s[n - 2];
	double d = 1;
	ks.push_back(make_pair(su-m, n - 2));

	for (int i = n - 3; i >= 1; i--) {
		if (s[i] <= m) {
			m = s[i];
			d++;
			double a = su / d;
			ks.push_back(make_pair(a, i));
		}
		else {
			su += s[i];
			su -= m;
			d++;
			double a = su / d;
			ks.push_back(make_pair(a, i));
		}
		su += m;
	}

	sort(ks.begin(), ks.end());

	int k = ks[ks.size() - 1].second;
	double l = ks[ks.size() - 1].first;
	z.push_back(k);

	for (int i = ks.size()-2; i > -1; i--) {
		if (ks[i].first != l) {
			break;
		}
		else {
			z.push_back(ks[i].second);
		}
	}

	sort(z.begin(), z.end());

	for (int i = 0; i < z.size(); i++) {
		fout << z[i] << endl;
	}


	return 0;
}