#include <bits/stdc++.h>
using namespace std;

#define FILE_IN "file.in"
#define FILE_OUT "file.out"
#define MAX_N 101
#define MAX_SUM 5001


int n, sum, cost[MAX_N];
bool DP[MAX_N][MAX_SUM], visited[MAX_N][MAX_SUM];
vector<int> numbers;

bool f(int i, int x) {
	if (!i) {
		if (x) DP[i][x] = false;
		else DP[i][x] = true;
		return DP[i][x];
	}
	if (!visited[i][x]) {
		visited[i][x] = true;
		if (cost[i] > x) {
			DP[i][x] = f(i - 1, x);
			return DP[i][x];
		}
		DP[i][x] = f(i - 1, x - cost[i]) || f(i - 1, x);
	}
	return DP[i][x];
}

bool in(int i, int x) {
	if (!f(i, x)) return false;
	if (!f(i - 1, x)) {
		if (f(i - 1, x - cost[i])) return true;
		return false;
	}
	return false;
}

int main(int argc, const char* argv[])
{
	ifstream fin(FILE_IN);
	ofstream fout(FILE_OUT, ios::app);
	cin >> n >> sum;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	if (!f(n, sum)) {
		cout << "No Solution" << endl;
		return 0;
	}
	int x = sum, i = n;
	while (x) {
		if (in(i, x)) {
			numbers.push_back(i);
			x -= cost[i];
			i--;
		}
		else i--;
	}
	for (long long j = numbers.size() - 1; j >= 0; j--) {
		cout << numbers[j] << ' ';
	}
	cout << endl;
	return 0;
}