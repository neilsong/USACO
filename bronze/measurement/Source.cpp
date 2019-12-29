#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ifstream fin("measurement.in");
	ofstream fout("measurement.out");

	vector <pair<long, pair<long,long>>> ip;
	map<long, long> log;

	map<long, long> pi;

	vector <long> l;

	long m, n, c;
	c = 0;

	cin >> n >> m;

	for (long i = 0; i < n; i++) {
		long d, cid, ic;
		cin >> d >> cid >> ic;
		ip.push_back(make_pair(d, make_pair(cid,ic)));
	}
	
	sort(ip.begin(), ip.end());
	
	long prev = 0;

	for (long i = 0; i < n; i++) {
		if (prev == ip[i].first) {
			c--;
		}
		log[ip[i].second.first] = m + ip[i].second.second;
		if (m + ip[i].second.second > m) {
			if (pi.count(ip[i].second.first) == 0) {
				pi[ip[i].second.first] = ip[i].second.second;
				m = ip[i].second.second;
				c++;
				if (l.size() > 0) {
					for (long j = 0; j < l.size(); j++) {
						if (pi[l[j]] < m) {
							pi.erase(l[j]);
							l.erase(l.begin() + j);
						}
					}
				}
			}
			else if (l.size() > 0) {
				for (long j = 0; j < l.size(); j++) {
					if (pi[l[j]] < m) {
						pi.erase(l[j]);
						l.erase(l.begin() + j);
					}
				}
				c++;
			}
			l.push_back(ip[i].second.first);
			m += ip[i].second.second;
		}
		else if (m + ip[i].second.second == m) {
			c++;
			pi[ip[i].second.first] = ip[i].second.second;
			l.push_back(ip[i].second.first);
		}
		else if (m + ip[i].second.second < m && pi.count(ip[i].second.first) != 0) {
			c++;
			pi.erase(ip[i].second.first);
			l.erase(find(l.begin(), l.end(), ip[i].second.first));
		}
		prev = ip[i].first;
	}

	cout << c << endl;

	return 0;
}