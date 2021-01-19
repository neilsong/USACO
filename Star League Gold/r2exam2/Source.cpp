#include <bits/stdc++.h>
using namespace std;
int V, A, B;
int p, mat[901][901], c;
bool negcycle = 0;
vector<vector<int>> mat1;
void solve()
{
	// Floyd-Warshall all shortest path
	for (int i = 0; i < V*V; i++)
		for (int j = 0; j < V*V; j++)
			if (mat[j][i]!=INT_MAX)
				for (int k = 0; k < V*V; k++)
					if (mat[i][k] != INT_MAX && (mat[j][k] == INT_MAX || mat[j][k] > mat[j][i] + mat[i][k]))
						mat[j][k] = mat[j][i] + mat[i][k];
	for (int i = 0; i < p; i++) if (mat[i][i] < 0) negcycle = 1;
}
int main(void) {
	cin >> V >> A >> B;
	p = V;
	mat1.resize(V);
	for (int i = 0; i < V; i++) {
		string idk;
		cin >> idk;
		for (auto k : idk) {
			mat1[i].push_back(k);
		}
	}
	for(int i =0; i< V*V; i++) {
		fill(mat[i], mat[i] + V*V+1, INT_MAX);
	}
	int count = 0;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (i != 0) {
				if (mat1[i][j] == mat1[i - 1][j]) {
					mat[count][count-V] = A;
					mat[count - V][count] = A;
				}
				else {
					mat[count][count-V] = B;
					mat[count-V][count] = B;;
				}
			}
			if (j != V - 1) {
				if (mat1[i][j+1] == mat1[i][j]) {
					mat[count][count +1] = A;
					mat[count +1][count] = A;
				}
				else {
					mat[count][count +1] = B;
					mat[count+1][count] = B;
				}
			}
			count++;
		}
	}
	solve();
	int Max = 0;
	for (int i = 0; i < V * V; i++) {
		for (int j = 0; j < V * V; j++) {
			Max = max(Max, mat[i][j]);
		}
	}
	if (Max == INT_MAX) {
		cout << 0 << endl;
		return 0;
	}
	cout << Max << endl;
}