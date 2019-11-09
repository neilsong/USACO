#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> start;
	vector<int> end;
	vector<int> covered;
	vector<int> cover;
	vector<int> fire;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		start.push_back(x);

		int y;
		cin >> y;
		start.push_back(y);
	}
	for (int i = 0; i < *max_element(end.begin(), end.end()) - 1; i++) {
		covered.push_back(0);
		cover.push_back(0);
	}
	for (int i = 0; i < n; i++) {
		fire.push_back(0);
		for (int j = start[i]; j < end[i]; j++) {
			covered[j]++;
			cover[j]++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = start[i]; j < end[i]; j++) {
			cover[j]--;
			for (int h = 0; h < *max_element(end.begin(), end.end()) - 1; h++) {
				if (cover[h] > 0) {
					fire[i]+=1;
				}
			}
			cover = covered;	
		}
	}
	cout << *max_element(fire.begin(), fire.end());
	return 0;
}