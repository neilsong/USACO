#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct State {
	int time;
	int index;
};


State newState(int a, int b) {
	State A;
	A.time = a;
	A.index = b;
	return A;
}

bool sortbytime(const State &a, const State &b) {
	return a.time < b.time;
}

int main(void) {

	ifstream fin("lifeguards.in");
	ofstream fout("lifeguards.out");

	std::set <int> set;
	int n;
	cin >> n;
	vector <State> l(2*n);

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		l[2 * i] = newState(start, i);
		l[2 * i + 1] = newState(end, i);
	}
	sort(l.begin(), l.end(),sortbytime);
	int actualCover = 0;
	vector <int> alone(n);
	int last = 0;
	for (State out : l) {
		if (set.size() == 1) {
			alone[*set.begin()] += out.time - last;
		}
		if (!set.empty()) {
			actualCover += out.time - last;
		}
		if (set.find (out.index) != set.end()) {
			set.erase(out.index);
		}
		else {
			set.insert(out.index);
		}
		last = out.time;
	}
	int ret = 0;
	for (int out : alone) {
		ret = max(ret, actualCover - out);
	}
	
	cout << ret << endl;

	return 0;
}