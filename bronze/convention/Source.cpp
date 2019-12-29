#include <bits/stdc++.h>
using namespace std;

int N, M, C, bt = 1000000000/2;

bool check() {

}

int binsearch(int hi, int lo) {
	if (lo >= hi) {
		return bt;
	}
	bt = (hi + lo) / 2;
	if (check()) {
		binsearch(bt-1, 0);
	}
	else {
		binsearch(1000000000, bt+1);
	}
}

int main(void) {
	ifstream fin("convention.in");
	ofstream fout("convention.out");
	cin >> N >> M >> C;
	int busT = binsearch(0, 1000000000);
}