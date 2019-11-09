#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> peaks;


struct mount {
	int x, y, xint;
};
vector<mount> xints;

bool sortbyxint(mount a, mount b) {
	if (a.xint == b.xint) {
		return a.x > b.x;
	}
	return a.xint < b.xint;
}

int main(void) {
	ifstream fin("mountains.in");
	ofstream fout("mountains.out");
	int n;
	fin >> n;
	xints.resize(2 * n);
	peaks.resize(n);
	for (int i = 0; i < n; i++) {
		fin >> peaks[i].first >> peaks[i].second;
		xints.push_back({ peaks[i].first, peaks[i].second, peaks[i].first - peaks[i].second });
	}
	std::sort(xints.begin(), xints.end(), sortbyxint);
	int M = 0;
	int ans = 1;
	for (int i = 1; i < xints.size(); i++) {
		if (xints[i].x + xints[i].y > xints[M].x + xints[M].y) {
			M = i;
			ans++;
		}
	}
	fout << ans << endl;
}