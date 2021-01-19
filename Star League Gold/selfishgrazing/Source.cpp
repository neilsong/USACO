#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graze;
int n;

bool sortbysec(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}


bool compatible(pair<int, int> a, pair<int, int> b) {
	return a.second <= b.first;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		graze.push_back({ s,e });
	}
	sort(graze.begin(), graze.end(), sortbysec);
	int ans = 1;
	pair<int, int> last = graze[0];
	for (int i = 1; i < n; i++) {
		if (compatible(last, graze[i])) {
			ans++;
			last = graze[i];
		}
	}
	cout << ans << endl;
}