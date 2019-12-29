#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isPoten(vector <string> spot, vector <string> p, int pos,int n) {
	vector <char> let;
	vector<char>nlet;
	vector <char> flet;
	for (int i = 0; i < n; i++) {
		let.push_back(p[i][pos]);
	}


	for (int i = 0; i < n; i++) {
		nlet.push_back(spot[i][pos]);
	}


	sort(let.begin(), let.end());
	sort(nlet.begin(), nlet.end());

	set_intersection(let.begin(), let.end(), nlet.begin(), nlet.end(), back_inserter(flet));

	if (flet.size() == 0) {
		return 1;
	}
	else {
		return 0;
	}

}

int main(void)
{
	ofstream fout("cownomics.out");
	ifstream fin("cownomics.in");

	int n, m;
	fin >> n >> m;

	vector <string> spot;
	vector <string> p;
	int count = 0;

	for (int i = 0; i < n; i++) {
		string c = "";
		for (int j = 0; j < m; j++) {
			char b;
			fin >> b;
			c += b;
		}
		spot.push_back(c);
	}

	for (int i = 0; i < n; i++) {
		string c = "";
		for (int j = 0; j < m; j++) {
			char b;
			fin >> b;
			c += b;
		}
		p.push_back(c);
	}

	for (int i = 0; i < m; i++) {
		if (isPoten(spot, p, i, n)) count++;
	}


	fout << count << endl;


	return 0;
}