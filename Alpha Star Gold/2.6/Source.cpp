#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> cows;

bool customsort(const pair<int, int> a, const pair<int, int> b) {
	if (a.first < a.second) {
		if (b.first < b.second) return a.first < b.first;
		return 1;
	}
	else{
		if (b.first >= b.second) return a.second > b.second;
		return 0;
	}
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, d;
		cin >> u >> d;
		cows.push_back({ u,d });
	}
	sort(cows.begin(), cows.end(), customsort);
	vector<int> line;
	int front = 0;
	int time = 0;
	for (auto i : cows) {
		if (time == 0) {
			time = i.first;
			line.push_back(i.second);
			continue;
		}
		time += i.first;
		int amt = i.first;
		while (front < line.size() && line[front] && amt > 0) {
			int tosub = min(line[front], amt);
			line[front] -= tosub;
			amt -= tosub;
			if (line[front] == 0) {
				front++;
			}
		}
		line.push_back(i.second);
	}
	if (front < line.size())
		if(line[front]) {
		while (front < line.size() && line[front]) {
			time += line[front];
			front++;
		}
	}
	cout << time << endl;
}