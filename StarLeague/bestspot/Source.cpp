#include <bits/stdc++.h>
using namespace std;
#define MAX 500

int p, mat[MAX][MAX], c, f, bsum = INT_MAX, b;
bool negcycle = 0;
vector<int> faves;

void solve()
{
	// Floyd-Warshall all shortest path
	for (int i = 0; i < p; i++)
		for (int j = 0; j < p; j++)
			if (mat[j][i])
				for (int k = 0; k < p; k++)
					if (mat[i][k] && (!mat[j][k] || mat[j][k] > mat[j][i] + mat[i][k]))
						mat[j][k] = mat[j][i] + mat[i][k];
	for (int i = 0; i < p; i++) mat[i][i] = 0;
}
int main(void) {
	// read paths
	cin >> p >> f>> c;
	faves.resize(f);
	for (int i = 0; i < f; i++) {
		cin >> faves[i];
		faves[i]--;
	}
	for (int i = 0; i < c; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		mat[--a][--b] = d, mat[b][a] = d;
	}
	solve();
	for (int i = 0; i < p; i++) {
		int sum = 0;
		for (auto j : faves) 
		{
			sum += mat[i][j];
		}
		if (bsum > sum) { bsum = sum; b = i + 1; }
	}
	cout << b << endl;
}

