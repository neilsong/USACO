#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct S {	
	long long next, prev,cur;
	bool nb, pb;
};

S test(S a, long long t) {
	if (a.next <= a.cur + t) {
		a.nb = 1;
	}
	if (a.prev >= a.cur - t) {
		a.pb = 1;
	}
	return a;
}

vector <pair<long long, bool>> cr(vector <pair<long long, bool>> line, long long t, int s) {
	S a;
	a.cur = line[s].first;
	a.next = line[s + 1].first;
	a.prev = line[s - 1].first;
}
int main(void)
{
	
	int n;
	int count = 0;
	cin >> n;

	vector <pair<long long, bool>> line;

	for (int i = 0; i < n; i++) {
		long long b;
		cin >> b;
		line.push_back(make_pair(b, 0));
	}

	sort(line.begin(), line.end());

	for (int i = 0; i < n; i++) {
		int c = 0;
		vector <pair<long long, bool>> l;
		l = cr(line, 1, i);
		for (int j = 0; j < n; j++) {
			if (l[j].second) {
				c++;
			}
		}
		count = max(count, c);
	}

	cout << count << endl;

	return 0;
}