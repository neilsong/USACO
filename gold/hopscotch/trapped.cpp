#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <string>
using namespace std;

struct Haybale {
	int position, size;
};

Haybale newHaybale(int sizeIn, int positionIn) {
	Haybale a;
	a.size = sizeIn;
	a.position = positionIn;
	return a;
}

bool sortbysize(const Haybale &a, const Haybale &b) {
	return a.size > b.size;
}

bool sortbypos(const Haybale &a, const Haybale &b) {
	return a.position < b.position;
}

int main(void)
{
	ifstream fin("trapped.in");
	ofstream fout("trapped.out");

	int n;
	fin >> n;

	vector <Haybale> bales(n);

	for (int i = 0; i < n; i++) {
		int size, position;
		fin >> size >> position;
		bales[i] = newHaybale(size, position);
	}

	sort(bales.begin(), bales.end(), sortbypos);

	vector <int> locations(n);

	std::map<int, int> map;
	std::map<int, int> locToSize;

	for (int i = 0; i < n; i++) {
		locations[i] = bales[i].position;
		map.insert(make_pair(locations[i], i));
		locToSize.insert(make_pair(bales[i].position, bales[i].size));
	}

	sort(bales.begin(), bales.end(), sortbysize);
	
	set<int> seen;
	int ans = 0;
	vector <bool> covered(n - 1);

	for (Haybale out : bales) {
		int index = map[out.position];
		if (seen.size() > 0 && *seen.rbegin() > index) {
			int higherIndex = *seen.upper_bound(index);
			int distance = locations[higherIndex] - locations[index];
			if (distance <= locToSize[locations[higherIndex]] && distance <= out.size) {
				int l = index;
				int r = higherIndex;
				if (!covered[l]) {
					for (int i = l; i < r; i++) {
						covered[i] = 1;
					}
				}
			}
		}
		if (seen.size() > 0 && *seen.begin() < index) {
			int lowerIndex = *(--seen.lower_bound(index));
			int distance = locations[index] - locations[lowerIndex];
			if (distance <= locToSize[locations[lowerIndex]] && distance <= out.size) {
				int l = lowerIndex;
				int r = index;
				if (!covered[l]) {
					for (int i = l; i < r; i++) {
						covered[i] = 1;
					}
				}
			}
		}
		seen.insert(index);
	}

	for (int i = 0; i < covered.size(); i++) {
		if (covered[i]) {
			ans += locations[i + 1] - locations[i];
		}
	}

	fout << ans;
	
	return 0;
}