#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	//fstreams
	ifstream fin("sleepy.in");
	ofstream fout("sleepy.out");

	//main variable declation
	int n;
	cin >> n;
	vector<int>l;

	//# of Steps + Input
	int s = 0;
	int smallind = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (l.size() != 0 && a < l[l.size() - 1]) {
			s = max(s, (int)l.size());
			smallind = i;
		}
		l.push_back(a);
	}
	cout << s << endl;

	vector <int> sorted;

	for (int i = l.size() - 1; i >= smallind; i--) {
		sorted.push_back(l[i]);
	}

	for (int i = 0; i < smallind; i++) {
		auto ins = lower_bound(sorted.begin(), sorted.end(), l[i]);
		int dist = abs(distance(ins, sorted.begin()));
		dist += s - 1 - i;
		sorted.insert(ins, l[i]);
		if (i != smallind - 1) {
			cout << (int)dist << " ";
		}
		else {
			cout << (int)dist;
		}
	}

	return 0;
}