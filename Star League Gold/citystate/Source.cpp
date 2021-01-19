#include <bits/stdc++.h>
using namespace std;

int main(void){
		ifstream fin("citystate.in");
		ofstream fout("citystate.out");

		long n;
		cin >> n;
		int count = 0;

		map<string, int> mymap;

		for (long i = 0; i < n; i++) {
			string city, state;
			string a;
			cin >> city >> state;
			a.push_back(city[0]);
			a.push_back(city[1]);
			if (a != state) {
				string c = a + state;
				if (i == 0) {
					mymap.insert(make_pair(c, 0));
				}
				mymap[c]++;
			}
		}

		for (auto it = mymap.begin(); it != mymap.end(); ++it) {
			string a = it->first.substr(2, 2) + it->first.substr(0, 2);
			count += mymap[it->first] * mymap[a];
		}

		cout << count / 2 << endl;


		return 0;
}