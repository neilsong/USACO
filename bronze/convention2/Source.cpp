#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

struct cow {
	int start, index,time;
};

cow newCow(int a, int b, int c) {
	cow A;
	A.start = a;
	A.time = b;
	A.index = c;
	return A;
}

bool sortbyst(const cow &a, const cow &b) {
	return a.start < b.start;
}

int main(void) {
	ifstream fin("convention2.in");
	ofstream fout("convention2.out");

	int a;
	cin >> a;
	vector <cow> cows;
	priority_queue <tuple> waiting;

	for (int i = 0; i < a; i++) {
		int s, in, t;
		cin >> s >> in >> t;
		in = a - in;
		cows.push_back(newCow(s, in, t));
	}

	sort(cows.begin(), cows.end(), sortbyst);

	int last = cows[0].start + cows[0].time;

	while (cows.size() > 0) {
		while (!waiting.empty()) {

		}
		if(cows.size() > 0) {
			last = cows[0].start + cows[0].time;
			for (int i = cows[0].start; i <= last; i++) {
				for (int j = 1; j < cows.size(); j++) {
					if (cows[j].start > i) {
						break;
					}
					else if (cows[j].start == i) {
						waiting.push(make_pair(cows[j].index, cows[j].start));
					}
				}
			}
		}
	}

	return 0;
}