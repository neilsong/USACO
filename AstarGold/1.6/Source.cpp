#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

string dir;

struct coord {
	int x, y, direct;
};

#define n dir.size()
//          0
//      3       1
//          2

set<pair<int, int>> unq;

int main(void) {
	cin >> dir;
	vector<coord> ps;
	ps.push_back({ 0,0,0 });
	for (int i = 0; i < dir.size(); i++) {
		if (dir[i] == 'F') {
			if (ps[i].direct == 0) ps.push_back({ ps[i].x,ps[i].y + 1, ps[i].direct });
			if (ps[i].direct == 1) ps.push_back({ ps[i].x + 1,ps[i].y, ps[i].direct });
			if (ps[i].direct == 2) ps.push_back({ ps[i].x,ps[i].y - 1 , ps[i].direct });
			if (ps[i].direct == 3) ps.push_back({ ps[i].x -1,ps[i].y , ps[i].direct});
		}
		else if (dir[i] == 'R') {
			if (ps[i].direct == 3) ps.push_back({ ps[i].x, ps[i].y, ps[i].direct - 3 });
			else ps.push_back({ ps[i].x, ps[i].y, ps[i].direct + 1 });
		}
		else {
			if (ps[i].direct == 0) ps.push_back({ ps[i].x, ps[i].y, ps[i].direct + 3 });
			else ps.push_back({ ps[i].x, ps[i].y, ps[i].direct - 1 });
		}
	}
	for (int i = 0; i < dir.size(); i++) {
		coord curcoord = { ps[i].x, ps[i].y , ps[i].direct };
		if (dir[i] == 'F') {
			coord prefinal = { ps[n].x, ps[n].y, ps[n].direct };
			if (curcoord.direct == 0) prefinal = { prefinal.x, prefinal.y - 1, prefinal.direct };
			if (curcoord.direct == 1) prefinal = { prefinal.x - 1,prefinal.y, prefinal.direct };
			if (curcoord.direct == 2) prefinal = { prefinal.x, prefinal.y + 1 , prefinal.direct };
			if (curcoord.direct == 3) prefinal = { prefinal.x + 1, prefinal.y , prefinal.direct };
			int deltax = prefinal.x - curcoord.x, deltay = prefinal.y - curcoord.y;
			pair<int, int> final = { curcoord.x + deltay, curcoord.y - deltax };
			unq.insert(final);
			prefinal = { ps[n].x, ps[n].y, ps[n].direct };
			if (curcoord.direct == 0) prefinal = { prefinal.x, prefinal.y - 1, prefinal.direct };
			if (curcoord.direct == 1) prefinal = { prefinal.x - 1,prefinal.y, prefinal.direct };
			if (curcoord.direct == 2) prefinal = { prefinal.x, prefinal.y + 1 , prefinal.direct };
			if (curcoord.direct == 3) prefinal = { prefinal.x + 1, prefinal.y , prefinal.direct };
			deltax = prefinal.x - curcoord.x; deltay = prefinal.y - curcoord.y;
			final = { curcoord.x - deltay, curcoord.y + deltax };
			unq.insert(final);
		}
		else if (dir[i] == 'R') {
			coord prefinal = { ps[n].x, ps[n].y, ps[n].direct };
			int deltax = prefinal.x - curcoord.x; int deltay = prefinal.y - curcoord.y;
			pair<int,int> final = { curcoord.x - deltax, curcoord.y - deltay };
			unq.insert(final);
			prefinal = { ps[n].x, ps[n].y, ps[n].direct };
			deltax = prefinal.x - curcoord.x; deltay = prefinal.y - curcoord.y;
			if (prefinal.direct == 0) prefinal = { prefinal.x, prefinal.y, prefinal.direct + 3 };
			else prefinal = { prefinal.x, prefinal.y, prefinal.direct - 1 };
			prefinal = { curcoord.x - deltay, curcoord.y + deltax, prefinal.direct };
			if (curcoord.direct == 0) prefinal = { prefinal.x, prefinal.y + 1, prefinal.direct };
			if (curcoord.direct == 1) prefinal = { prefinal.x + 1,prefinal.y, prefinal.direct };
			if (curcoord.direct == 2) prefinal = { prefinal.x, prefinal.y - 1 , prefinal.direct };
			if (curcoord.direct == 3) prefinal = { prefinal.x - 1, prefinal.y , prefinal.direct };
			unq.insert({ prefinal.x, prefinal.y });
		}
		else {
			coord prefinal = { ps[n].x, ps[n].y, ps[n].direct };
			int deltax = prefinal.x - curcoord.x; int deltay = prefinal.y - curcoord.y;
			pair<int, int> final = { curcoord.x - deltax, curcoord.y - deltay };
			unq.insert(final);
			prefinal = { ps[n].x, ps[n].y, ps[n].direct };
			deltax = prefinal.x - curcoord.x; deltay = prefinal.y - curcoord.y;
			if (prefinal.direct == 0) prefinal = { prefinal.x, prefinal.y, prefinal.direct + 3 };
			else prefinal = { prefinal.x, prefinal.y, prefinal.direct - 1 };
			prefinal = { curcoord.x + deltay, curcoord.y - deltax, prefinal.direct };
			if (curcoord.direct == 0) prefinal = { prefinal.x, prefinal.y + 1, prefinal.direct };
			if (curcoord.direct == 1) prefinal = { prefinal.x + 1,prefinal.y, prefinal.direct };
			if (curcoord.direct == 2) prefinal = { prefinal.x, prefinal.y - 1 , prefinal.direct };
			if (curcoord.direct == 3) prefinal = { prefinal.x - 1, prefinal.y , prefinal.direct };
			unq.insert({ prefinal.x, prefinal.y });
		}
	}
	cout << unq.size();
}