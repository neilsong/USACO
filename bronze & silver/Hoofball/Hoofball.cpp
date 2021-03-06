#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortbysec(const pair<int, int> &a,
	const pair<int, int> &b)
{
	return (a.second < b.second);
}

vector <pair<int, int>> swap(vector <pair<int, int>> ifpass, int i, int j) {
	vector<pair<int, int>> y;
	y.push_back(ifpass[i]);
	ifpass[i] = ifpass[j];
	ifpass[j] = y[0];
	return ifpass;
}

int calc(vector <pair<int, int>> ds, int i) {
	if (i == 0) {
		return 1;
	}
	else if (i == ds.size() - 1) {
		return (i - 1);
	}
	else {
		int a = ds[i + 1].second;
		int b = ds[i - 1].second;
		int c = ds[i].second;
		if (abs(c - a) < abs(c - b)) {
			return (i + 1);
		}
		else {
			return (i - 1);
		}
	}
}

int main(void)
{

	ifstream fin("hoofball.in");
	ofstream fout("hoofball.out");

	vector <pair<int, int>> ifpass;
	vector <pair<int,int>> ds;

	int n;
	fin >> n;

	for (int i = 0; i < n; i++) {
		int d;
		fin >> d;
		ifpass.push_back(make_pair(i, 0));
		ds.push_back(make_pair(i,d));
	}

	sort(ds.begin(), ds.end(), sortbysec);
	for (int i = 0; i < ds.size(); i++) {
		for (int j = 0; j < ifpass.size(); j++) {
			if (ds[i].first == ifpass[j].first) {
				ifpass = swap(ifpass, i, j);
			}
		}
	}


	for (int i = 0; i < ds.size(); i++) {
		int j = calc(ds, i);
		ifpass[j].second++;
	}
	int o=0;

	for (int i = 0; i < ifpass.size(); i++) {
		if (ifpass[i].second == 0) o++;
		if (i < calc(ds, i) && calc(ds, calc(ds, i))==i && ifpass[i].second == 1 && ifpass[calc(ds, i)].second == 1) o++;
	}

	fout << o;


	return 0;
}