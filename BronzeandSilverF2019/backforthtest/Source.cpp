#include<iostream>
#include<fstream>
#include<vector>
#include<set>
using namespace std;

set<int> milkvalues;

void friday(int milkvalue, vector<int> b1, vector<int> b2) {
	for (int i = 0; i < 11; i++) {
		milkvalues.insert(milkvalue + b2[i]);
	}
}
void tursday(int milkvalue, vector<int> b1, vector<int> b2) {
	for (int i = 0; i < 11; i++) {
		vector<int> tempb2 = b2;
		tempb2.push_back(b1[i]);
		vector<int> tempb1 = b1;
		tempb1.erase(tempb1.begin() + i);
		friday(milkvalue - b1[i], tempb1, tempb2);
	}
}
void wednesday(int milkvalue, vector<int> b1, vector<int> b2) {
	for (int i = 0; i < 11; i++) {
		vector<int> tempb1 = b1;
		tempb1.push_back(b2[i]);
		vector<int> tempb2 = b2;
		tempb2.erase(tempb2.begin() + i);
		tursday(milkvalue + b2[i], tempb1, tempb2);
	}
}
void tusday(int milkvalue, vector<int> b1, vector<int> b2) {
	for (int i = 0; i < 10; i++) {
		vector<int> tempb2 = b2;
		tempb2.push_back(b1[i]);
		vector<int> tempb1 = b1;
		tempb1.erase(tempb1.begin() + i);
		wednesday(milkvalue - b1[i], tempb1, tempb2);
	}
}
int main() {
	ifstream fin("backforth.in");
	ofstream fout("backforth.out");
	vector<int> b1;
	vector<int> b2;
	int milkvalue = 1000;
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		b1.push_back(x);
	}
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		b2.push_back(x);
	}
	tusday(milkvalue, b1, b2);
	cout << milkvalues.size();
	return 0;
}