#include <bits/stdc++.h>
using namespace std;
#define MAX 500

int p, mat[MAX][MAX], c;
bool negcycle = 0;

void solve()
{
	// Floyd-Warshall all shortest path
	for (int i = 0; i < p; i++)
		for (int j = 0; j < p; j++)
			if (mat[j][i])
				for (int k = 0; k < p; k++)
					if (mat[i][k] && (!mat[j][k] || mat[j][k] > mat[j][i] + mat[i][k]))
						mat[j][k] = mat[j][i] + mat[i][k];
	for (int i = 0; i < p; i++) if (mat[i][i] < 0) negcycle = 1;
}
int main(void) {
	// read paths
	cin >> p >> c;
	for (int i = 0; i < c; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		mat[--a][--b] = d, mat[b][a] = d;
	}
}