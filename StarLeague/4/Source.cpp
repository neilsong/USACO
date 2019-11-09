#include <bits/stdc++.h>
using namespace std;


int mincount = INT_MAX;
int recurse(int x, int y, int count) {
	
	if (x != y) {
		if (x > y) {
			recurse(x - 1, y, count + 1);
		}
		if (x < y) {
			if (x > 1 && abs(y - (x-1)*2) < abs(y-(x+1)) && abs(y - (x - 1) * 2) < abs(y - (x *2))) {
				recurse((x - 1) * 2, y, count + 2);
			}
			if (abs(y - (x * 2) < abs(y - (x + 1)))) {
				recurse(x * 2, y, count + 1);
			}			
			recurse(x + 1, y, count + 1);
		}
	}
	else {
		mincount = min(count, mincount);
	}
	return count;
}

int main(void) {
	int x, y;
	cin >> x >> y;
	int count = recurse(x, y, 0);
	cout << mincount;
}