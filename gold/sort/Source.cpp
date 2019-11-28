#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
//set<int> sorted;

int main(void) {
	ifstream fin("sort.in");
	ofstream fout("sort.out");

	int n;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bool sorted = 0;
	int counter = 0;
	while (!sorted) {
		sorted = 1;
		counter++;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
			}
		}
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
			}
		}
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				sorted = 0;
			}
		}
	}
	cout << counter << endl;
	return 0;
}