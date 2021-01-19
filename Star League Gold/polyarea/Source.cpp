#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> polys;
vector<pair<pair<int, int>,pair<int,int>>> fences;
vector<pair<int, int>> cows;
vector<int> visited;
int N, C;
vector<long long> compare;


bool onSegment(pair<int,int> p, pair<int,int> q, pair<int,int> r)
{
	if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
		q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second))
		return true;

	return false;
}


int orientation(pair<int,int> p, pair<int,int> q, pair<int,int> r)
{

	int val = (q.second - p.second) * (r.first - q.first) -
		(q.first - p.first) * (r.second - q.second);

	if (val == 0) return 0; 

	return (val > 0) ? 1 : 2;
}


int doIntersect(pair<int,int> p1, pair<int,int> q1, pair<int,int> p2, pair<int,int> q2)
{

	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if (o1 != o2 && o3 != o4)
		return 1;


	if (o1 == 0 && onSegment(p1, p2, q1)) return 1;

	 
	if (o2 == 0 && onSegment(p1, q2, q1)) return 1;


	if (o3 == 0 && onSegment(p2, p1, q2)) return 1;

	if (o4 == 0 && onSegment(p2, q1, q2)) return 1;

	return 0; 
}



int main(void) {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		fences.push_back({ {x1,x2},{y1,y2} });
	}
	for (int i = 0; i < C; i++) {
		int x, y;
		cin >> x >> y;
		cows.push_back({ x,y });
	}
	visited.resize(N);
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		pair<int, int> start = fences[i].first;
		pair<int, int> last = fences[i].second;
		vector<pair<int, int>> poly;
		poly.push_back(start);
		while (start != last) {
			for (int j = 0; j < N; j++) {
				if (visited[j]) continue;
				if (fences[j].first == last) {
					poly.push_back(last);
					last = fences[j].second;
					visited[j] = 1;
				}
				else if (fences[j].second == last) {
					poly.push_back(last);
					last = fences[j].first;
					visited[j] = 1;
				}
			}
		}
		poly.push_back(last);
		polys.push_back(poly);
	}
	vector<bitset<334>> setans(C);
	for (int i = 0; i < C; i++) {
		pair<int, int> p2 = { 1000000, cows[i].second + 1 };
		for (int j = 0; j < polys.size(); j++) {
			int intersect = 0;
			int ind = 0;
			for (ind = 0; ind <= polys.size() - 1; ind++) {
				intersect += doIntersect(cows[i], p2, polys[j][ind], polys[j][ind + 1]);
			}
			if (intersect % 2 == 1) {
				setans[i].set(j,1);
			}
		}
	}
	for (auto i : setans) {
		compare.push_back(i.to_ullong());
	}
	set<int> unique;
	int ans = 0;
	for (auto i : compare) {
		unique.insert(i);
	}
	for (auto i : unique) {
		ans = max(ans, (int)count(compare.begin(), compare.end(), i));
	}
	cout << ans << endl;
}