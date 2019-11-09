#include <bits/stdc++.h>
using namespace std;

string in;
string aval;
int N;
vector<int> n, r;

//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS
//WORK IN PROGRESS


int main(void) {
	cin >> N >> in >> aval;
	n.resize(3);
	r.resize(3);
	for (int i = 0; i < N; i++) {
		r[in[i] - 'a']++;
		n[aval[i] - 'a']++;
	}
	string ans = "";
	for (int i = 0; i < N; i++) {
		string abc = "abc";
		int ind = in[i] - 'a';
		r[ind]--;
		abc.erase(abc.begin() + ind);
		for (int j = 0; j < 2; j++) {
			if (abc[j] == 'a') {
				int next;
				j == 0 ? next = 1 : next = 0;
				if (r[abc[next] - 'a'] < n[0] + n[1] && n[0] > 0) {
					n[0]--;
					ans += 'a';
					break;
				}
			}
			else if (abc[j] == 'b') {
				int next;
				j == 0 ? next = 1 : next = 0;
				if (r[abc[next] - 'a'] < n[0] + n[1] && n[1] > 0) {
					n[1]--;
					ans += 'b';
					break;
				}
			}
			else {
				int next;
				j == 0 ? next = 1 : next = 0;
				if (r[abc[next] - 'a'] < n[2] + n[0] && n[2] > 0) {
					n[2]--;
					ans += 'c';
				}
			}
		}
	}
	cout << ans << endl;
}