#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

long long ways = 0;

void same(vector <string> a) {
	for (int i = 1; i < a.size() - 1; i++) {
		for (int j = 1; j < a[0].length()-1; j++) {
			if (a[i][j] != a[0][0]) {
				ways++;
			}
		}
	}
}

void nsame(vector <string> a) {
	ways++;
	vector <string> b;
	vector <string> f;
	for (int i = 1; i < a.size()-1; i++) {
		string l = "";
		for (int j = 1; j < a[0].length()-1; j++) {
			l.push_back(a[i][j]);
		}
		b.push_back(l);
	}
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < b[0].length(); j++) {
			if (b[i][j] != a[0][0]) {
				for (int m = 1+i; m < a.size(); m++) {
					string z = "";
					for (int l = 1+j; l < a[0].length(); l++) {
						z.push_back(a[m][l]);
					}
					f.push_back(z);
				}
				same(f);
			}
			
		}
	}
	
}



int main(void)
{

	ifstream fin("hopscotch.in");
	ofstream fout("hopscotch.out");
	int r, c;
	cin >> r >> c;

	vector <string> a;
	a.resize(r);

	for (int i = 0; i < r; i++) {
		cin >> a[i];
	}

	if (a[0][0] != a[r-1][c-1]) {
		nsame(a);
	}
	else {
		same(a);
	}

	cout << ways << endl;

	return 0;
}