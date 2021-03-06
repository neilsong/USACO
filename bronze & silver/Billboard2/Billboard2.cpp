#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Rect {
	int x1, x2, y1, y2;
};

int Area(Rect r) {
	return (r.x2 - r.x1) * (r.y2 - r.y1);
}

int Intersect_Area(Rect b, Rect t) {
	int x_overlap = max(0, min(b.x2, t.x2) - max(b.x1, t.x1));
	int y_overlap = max(0, min(b.y2, t.y2) - max(b.y1, t.y1));
	return x_overlap* y_overlap;
}

int CC(int x, int y, Rect b) {
	if (x >= b.x1 && x <= b.x2 && y >= b.y1 && y <= b.y2) return 1;
	return 0;
}

int main(void)
{
	ifstream fin("billboard.in");
	ofstream fout("billboard.out");
	Rect a, b;
	fin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	fin >> b.x1 >> b.y1 >> b.x2 >> b.y2;


	int ia = Intersect_Area(a,b);

	int cornercount = 0;
	cornercount += CC(a.x1, a.y1, b);
	cornercount += CC(a.x2, a.y1, b);
	cornercount += CC(a.x1, a.y2, b);
	cornercount += CC(a.x2, a.y2, b);

	if (cornercount < 2) {
		fout << Area(a) << endl;
	}
	else if (cornercount == 4) {
		fout << 0 << endl;
	}
	else {
		fout << Area(a) - ia << endl;
	}
	

	return 0;
}