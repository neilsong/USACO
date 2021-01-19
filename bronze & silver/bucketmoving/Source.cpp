#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int main(void) {
	ifstream fin("backforth.in");
	ofstream fout("backforth.out");

	vector <int> b1, b2;

	map<int, int> s;

	int fc = 0;


	for (int i = 0; i < 10; i++) {
		int a;
		fin >> a;
		b1.push_back(a);
	}


	for (int i = 0; i < 10; i++) {
		int a;
		fin >> a;
		b2.push_back(a);
	}

	for (int i = 0; i < b1.size(); i++) {
		int t = 1000;
		vector <int> t1 = b1;
		vector <int> t2 = b2;
		t -= t1[i];
		t2.push_back(t1[i]);
		t1.erase(t1.begin()+i);
		for (int j = 0; j < t2.size(); j++) {
			int w = t;
			vector <int> w1 = t1;
			vector <int> w2 = t2;
			w += w2[j];
			w1.push_back(w2[j]);
			w2.erase(w2.begin() + j);
			for (int k = 0; k < w1.size(); k++) {
				int th = w;
				vector <int> th1 = w1;
				vector <int> th2 = w2;
				th -= th1[k];
				th2.push_back(w1[k]);
				th1.erase(th1.begin() + k);
				for (int l = 0; l < th2.size(); l++) {
					int f = th;
					f += th2[l];
					if (s.count(f) == 0) {
						s[f] = 1;
						fc++;
					}
				}
			}

		}
	}
	
	fout << fc << endl;

	return 0;
}