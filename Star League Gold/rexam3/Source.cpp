#include <bits/stdc++.h>
	using namespace std;

	int main(void) {
		int n, d;
		cin >> n >> d;
		multimap<int,int> coords;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			coords.insert(make_pair(a, b));
		}
		set<int> raindropsy;
		raindropsy.insert(coords.begin()->second);
		multimap<int, int>::iterator pos1 = coords.begin(), pos2 = coords.begin();
		int ans = INT_MAX;
		while (pos2 != coords.end()) {
			bool Min = 1;
			if (*raindropsy.rbegin() - *raindropsy.begin() < d) {
				pos2++;
				if (pos2 == coords.end()) {
					break;
				}
				raindropsy.insert(pos2->second);
				Min = 0;
			}
			else {
				while (true) {
					if (*raindropsy.rbegin() - *raindropsy.begin() >= d) {
						if (pos2->first - pos1->first != 0) {
							ans = min(ans, pos2->first - pos1->first);
						}
					}
					else { Min = 0; break; }
					pos1++;
					raindropsy.erase(pos1->second);
				}
			}
			if (Min && pos1 != pos2) {
				if (pos2->first - pos1->first != 0) {
					ans = min(ans, pos2->first - pos1->first);
				}
				
			}

		}
		if (ans == INT_MAX) {
			cout << -1 << endl;
		}
		else {
			cout << ans << endl;
		}
		
	}