#include <bits/stdc++.h>
using namespace std;

vector<char> order;
vector<int> outmap;
int nf;

void solve(int pos) {
	if (pos == order.size()) {
		for (auto i : order) cout << i;
		cout << endl;
	}
	for (auto i : outmap) {
		order[pos] = i;
		solve(pos + 1);
	}
}

int main(void) {
	int r, c;
	cin >> r >> c;
	vector<vector<char>>mat(r);
	
	
	set<char>frames;
	for (int i = 0; i < r; i++) {
		mat[i].resize(c);
		for (int j = 0; j < c; j++) {
			cin >> mat[i][j];
			if(mat[i][j] != '.')frames.insert(mat[i][j]);
		}
	}
	outmap.resize(frames.size());
	order.resize(frames.size());
	vector<pair<int, int>> mincoord(frames.size()), maxcoord(frames.size());
	fill(mincoord.begin(), mincoord.end(), make_pair(INT_MAX,INT_MAX));
	fill(maxcoord.begin(), maxcoord.end(), make_pair(0, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (mat[i][j] != '.') {
				mincoord[mat[i][j] - 'A'].first = min(mincoord[mat[i][j] - 'A'].first, i);
				mincoord[mat[i][j] - 'A'].second = min(j, mincoord[mat[i][j] - 'A'].second);
				maxcoord[mat[i][j] - 'A'].first = max(maxcoord[mat[i][j] - 'A'].first, i);
				maxcoord[mat[i][j] - 'A'].second = max(j, maxcoord[mat[i][j] - 'A'].second);
			}
		}
	}
	int ind = 0;
	for (auto i : frames) {
		ind = i - 'A';
		set<char> outg;
		for (int h = mincoord[ind].first; h <= maxcoord[ind].first; h++) {
			bool y = 0;
			if (h == mincoord[ind].first || maxcoord[ind].first == h) {
				y = 1;
			}
			for (int j = mincoord[ind].second; j <= maxcoord[ind].second; j++) {
				if (!y) {
					
				}
				if (mat[h][j] != '.' && mat[h][j] != i && outg.find(mat[h][j]) == outg.end()) {
					outmap[mat[h][j] - 'A']++;
					outg.insert(mat[h][j]);
				}
			}
		}
	}
	sort(outmap.begin(), outmap.end());
}