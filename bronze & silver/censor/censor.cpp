#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(void)
{
	ifstream fin("censor.in");
	ofstream fout("censor.out");
	string c;
	cin >> c;
	string a;
	cin >> a;
	
	int f = 0;

	while (c.find(a) != string::npos) {
		if (c.find(a, f) != string::npos) {
			f = c.find(a, f);
			c.erase(f, a.length());
			f = f - a.length() + 1;
		}
		else {
			f = 0;
		}
	}

	cout << c << endl;


	return 0;
}