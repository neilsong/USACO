#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;



vector <long long> cows, farms;
vector <pair<long long, long long>> stores;


long long store(long long q) {
	long long MO = 0;
	vector <pair<long long, long long>> sts = stores;
	for (long long i = 0; i < stores.size(); i++) {
		while (sts[i].first != 0) {
			long long a = sts[i].first;
			MO += sts[i].second * min(a, q);
			sts[i].first -= min(a, q);
			q -= min(a, q);
			if (q == 0) {
				break;
			}
		}
		if (q == 0) {
			break;
		}
	}

	return MO;
}

long long combo(void) {
	long long Q = 0;
	long long a = 0;
	long long q = accumulate(cows.begin(), cows.end(),0);
	for (long long i = 1; i < cows.size(); i++) {
		a += farms[i-1];
		q -= cows[i - 1];
		long long b = store(q);
		long long m = a + b;
		Q = max(Q, m);
	}
	return Q;
}



bool sortinrev(const pair<long long, long long> &a,
	const pair<long long, long long> &b)
{
	return (a.second > b.second);
}

int main(void) {
	ifstream fin("rental.in");
	ofstream fout("rental.out");

	long long tot = 0;

	long long N, M, R;
	fin >> N >> M >> R;

	for (long long i = 0; i < N; i++) {
		long long b;
		fin >> b;
		cows.push_back(b);
	}
	for (long long i = 0; i < M; i++) {
		long long a, b;
		fin >> a >> b;
		stores.push_back(make_pair(a, b));
	}
	for (long long i = 0; i < R; i++) {
		long long b;
		fin >> b;
		farms.push_back(b);
	}

	sort(cows.begin(), cows.end());
	sort(farms.rbegin(), farms.rend());
	sort(stores.begin(), stores.end(), sortinrev);

	tot = combo();

	fout << tot << endl;

	return 0;
}