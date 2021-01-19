#include <bits/stdc++.h>
using namespace std;
int Tmax, n;
vector <int> d;

bool isok(int K) {
	priority_queue <int, vector<int>, greater<int>> pq;
	for (int i = 0; i < K; i++) {
		pq.push(0);
	}
	for (int i = 0; i < n; i++) {
		int avail = pq.top();
		pq.pop();
		if (avail + d[i] >= Tmax) {
			return 0;
		}
		pq.push(avail + d[i]);
	}
	return 1;
}

int binsearch() {
	int lo = 1;
	int hi = n;
	int k = (lo + hi) / 2;
	while (lo <= hi) {
		int &mid = k;
		mid = (hi + lo) / 2;
		if (isok(mid)) hi = mid-1;
		else lo = mid + 1;
	}
	return k;
}

int main(void) {
	cin >> n >> Tmax;
	for (int i = 0; i < n; i++) {
		int cow;
		cin >> cow;
		d.push_back(cow);
	}
	cout << binsearch();
}