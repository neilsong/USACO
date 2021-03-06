#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

vector <pair<int, int>> boots;
vector <int> ts;

int gc = boots.size();

void recur(int pos, int s, int c, int post) {
	if (ts[post] == 0 && post != 0) {
		gc = min(gc, c);
		return;
	}
	if (pos == boots.size()) {
		return;
	}
	if (boots[pos].first < ts[post] && s == 0) {
		recur(pos + 1, 0, c + 1, post);
	}
	if (s > boots[pos].second) {
		recur(pos + 1, 0, c + 1, post - s);
	}
	if (boots[pos].first < ts[post] && s != 0) {
		recur(pos, s + 1, c, post + 1);
	}
	if (boots[pos].first >= ts[s] && s != 0) {
		recur(pos, 0, c, post);
	}
	recur(pos, s + 1, c, post + 1);
}

int main(void)
{
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		int m;
		cin >> m;
		ts.push_back(m);
	}

	for (int i = 0; i < b; i++) {
		int m, n;
		cin >> m >> n;
		boots.push_back(make_pair(m, n));
	}

	recur(0, 0, 0, 0);

	cout << gc << endl;

	return 0;
}