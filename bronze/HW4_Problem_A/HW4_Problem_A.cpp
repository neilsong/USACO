#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	string s1;
	string s2;
	long long i1 = 1;
	long long i2 = 1;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s1.length(); i++) {
		i1 *= (int)s1[i]-64;
	}
	for (int i = 0; i < s2.length(); i++) {
		i2 *= (int)s2[i]-64;
	}
	i1 %= 47;
	i2 %= 47;
	if (i1 == i2) {
		cout << "GO" << endl;
	}
	else {
		cout << "STAY" << endl;
	}
		return 0;
}