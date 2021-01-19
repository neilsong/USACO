#include <bits/stdc++.h>
using namespace std;
int n, f, c;
vector<vector<int>> sol;
vector<int> v, fields;

vector<int> ispos(10000);

void check()
{
	ispos[0] = 0;
	for (int i = 0; i < v.size(); i++) {
		int val = v[i];
		if (ispos[val]) continue;
		for (int j = 0; j + val < 10000; j++) {
			if (ispos[j] || j== 0) ispos[j + val] = ispos[j]+1;
		}
	}
}
int main(void) {
	cin >> f >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	fields.resize(f);
	int carry = 0;
	for (int i = 0; i < f; i++) {
		cin >> fields[i];
		int temp = carry;
		carry += fields[i] - carry;
		fields[i] -= temp;
		if(carry)carry--;
	}
	int ans = 0;
	check();
	for (auto i : fields) {
		if (i != 0) {
			ans += ispos[i];
		}
	}
	cout << ans << endl;
	return 0;
}