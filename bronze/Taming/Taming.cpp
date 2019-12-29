#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(void)
{
	ofstream fout("taming.out");
	ifstream fin("taming.in");

	int loop;
	fin >> loop;
	vector <int> log;
	for (int i = 0; i < loop; i++) {
		int t;
		fin >> t;
		log.push_back(t);
	}
	
	if (log[0] > 0) {
		fout << "-1" << endl;
		return 0;
	}

	log[0] = 0;

	int q=-1, max=0, min=0;

	for (int i = log.size()-1; i >= 0; i--) {
		if (q != -1 && log[i] != -1 && log[i] != q) {
			fout << "-1" << endl;
			return 0;
		}
		if (q == -1) {
			q = log[i];
		}
		if (log[i] == -1) {
			log[i] = q;
		}
		if (log[i] == 0) {
			min++;
		}
		if (log[i] == -1) {
			max++;
		}
		if (q > -1) {
			q--;
		}
	}

	fout << min << " " << min + max << endl;

	return 0;
}