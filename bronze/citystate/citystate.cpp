#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<fstream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

int main(void)
{
	ifstream fin("citystate.in");
	ofstream fout("citystate.out");

	long n;
	fin >> n;
	long long count = 0;

	map<string,int> mymap;
	


	for (long i = 0; i < n; i++) {
		string city, state;
		string a;
		fin >> city >> state;
		a.push_back(city[0]);
		a.push_back(city[1]);
		if (a != state) {
			string c = a + state;
			if (!mymap.count(c)) {
				mymap[c] = 0;
			}
			mymap[c]++;
		}
	}

	for (map<string, int>::iterator it = mymap.begin(); it != mymap.end();++it) {
		string a = it->first.substr(2, 2) + it->first.substr(0, 2);
		count += mymap[it->first] * mymap[a];
	}



	fout << count/2 << endl;


	return 0;
}