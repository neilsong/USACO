#include <bits/stdc++.h>
using namespace std;

//Credit: GeeksforGeeks Kandane's Algorithm DP Paradigm O(n) that catches all negative exception Mohit Kumar
int maxSubArraySum(vector <int> a, int size)
{
	int max_so_far = a[0];
	int curr_max = a[0];

	for (int i = 1; i < size; i++)
	{
		curr_max = max(a[i], curr_max + a[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	return max_so_far;
}
int main(void) {
	vector <int> a;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		a.push_back(b);
	}
	cout << maxSubArraySum(a, n);

}