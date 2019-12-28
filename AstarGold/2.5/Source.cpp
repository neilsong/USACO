#include <bits/stdc++.h>
using namespace std;

struct event {
	int x, yt, yb; bool t; int id;
};

int n;
set<pair<int, bool>> nenclrect;
vector<event> rects;

bool sortbyx1(const event a, const event b) {
	return a.x < b.x;
}

int main(void) {

	cin >> n;
	vector<int> ids(n);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		rects.push_back({ x1, y2, y1, 0 , i});
		rects.push_back({ x2, y2, y1, 1 , i});
	}
	sort(rects.begin(), rects.end(), sortbyx1);
	int ans = 0;
	for (auto i : rects) {
		if (nenclrect.empty()) { 
			ans++;
			nenclrect.insert({ i.yt, 0 });
			nenclrect.insert({ i.yb, 1 });
			ids[i.id] = 1;
			continue;
		}
		set<pair<int, bool>>::iterator iter = nenclrect.lower_bound({ i.yt, 0 });
		if (!i.t) {
			if (iter == nenclrect.end() || iter->second == 1) {
				ans++;
				ids[i.id] = 1;
				nenclrect.insert({ i.yt, 0 });
				nenclrect.insert({ i.yb, 1 });
			}
		}
		else {
			if (ids[i.id] == 1) {
				nenclrect.erase({ i.yt, 0 });
				nenclrect.erase({ i.yb,1 });
			}
			
		}
	}
	cout << ans << endl;
}