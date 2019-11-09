//#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void fillArray(vector<int> &ans, int s, int t, int b) {
	for (int i = 0; i + s <= t; i++) {
		int x = b;
		x = b + ans[i + s];
		ans[i + s] = x;
	}
}
int max(vector<int> ans) {
	int a = 0;
	for (int i = 0; i < 1002; i++) {
		if (ans[i] > a) {
			a = ans[i];
		}
	}
	return a;
}

int main()
{
	ofstream fout("blist.out");
	ifstream fin("blist.in");
	int n;
	cin >> n;
	int s, t, b;
vector<int> ans(1001);
	for (int i = 0; i < n; i++) {
		cin >> s >> t >> b;
		fillArray(ans, s, t, b);
	}
	cout << max(ans);

}