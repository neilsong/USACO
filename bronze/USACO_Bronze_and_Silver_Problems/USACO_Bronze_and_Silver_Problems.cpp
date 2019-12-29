#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

char b[4][4];

int conversion(string a) {
	int x = 0;
	for (int i = 0; i < a.length(); i++) {
		x += (int)a[i];
	}
	return x;
}

int singlewin(char x) {
	if (b[0][0] == x && b[0][1] == x && b[0][2] == x) {
		return 1;
	}
	else if (b[1][0] == x && b[1][1] == x && b[1][2] == x) {
		return 1;
	}
	else if (b[2][0] == x && b[2][1] == x && b[2][2] == x) {
		return 1;
	}
	else if (b[0][0] == x && b[1][0] == x && b[2][0] == x) {
		return 1;
	}
	else if (b[0][1] == x && b[1][1] == x && b[2][1] == x) {
		return 1;
	}
	else if (b[0][2] == x && b[1][2] == x && b[2][2] == x) {
		return 1;
	}
	else if (b[0][0] == x && b[1][1] == x && b[2][2] == x) {
		return 1;
	}
	else if (b[0][2] == x && b[1][1] == x && b[2][0] == x) {
		return 1;
	}
	else {
		return 0;
	}
}

int teamwin(char x, char y) {
	if (b[0][0] == y && b[0][1] == x && b[0][2] == x) {
		return 1;
	}
	else if (b[0][0] == x && b[0][1] == y && b[0][2] == x) {
		return 1;
	}
	else if (b[0][0] == x && b[0][1] == x && b[0][2] == y) {
		return 1;
	}
	else if (b[1][0] == y && b[1][1] == x && b[1][2] == x) {
		return 1;
	}
	else if (b[1][0] == x && b[1][1] == y && b[1][2] == x) {
		return 1;
	}
	else if (b[1][0] == x && b[1][1] == x && b[1][2] == y) {
		return 1;
	}
	else if (b[2][0] == y && b[2][1] == x && b[2][2] == x) {
		return 1;
	}
	else if (b[2][0] == x && b[2][1] == y && b[2][2] == x) {
		return 1;
	}
	else if (b[2][0] == x && b[2][1] == x && b[2][2] == y) {
		return 1;
	}
	else if (b[0][0] == y && b[1][0] == x && b[2][0] == x) {
		return 1;
	}
	else if (b[0][0] == x && b[1][0] == y && b[2][0] == x) {
		return 1;
	}
	else if (b[0][0] == x && b[1][0] == x && b[2][0] == y) {
		return 1;
	}
	else if (b[0][1] == y && b[1][1] == x && b[2][1] == x) {
		return 1;
	}
	else if (b[0][1] == x && b[1][1] == y && b[2][1] == x) {
		return 1;
	}
	else if (b[0][1] == x && b[1][1] == x && b[2][1] == y) {
		return 1;
	}
	else if (b[0][2] == y && b[1][2] == x && b[2][2] == x) {
		return 1;
	}
	else if (b[0][2] == x && b[1][2] == y && b[2][2] == x) {
		return 1;
	}
	else if (b[0][2] == x && b[1][2] == x && b[2][2] == y) {
		return 1;
	}
	else if (b[0][0] == y && b[1][1] == x && b[2][2] == x) {
		return 1;
	}
	else if (b[0][0] == x && b[1][1] == y && b[2][2] == x) {
		return 1;
	}
	else if (b[0][0] == x && b[1][1] == x && b[2][2] == y) {
		return 1;
	}
	else if (b[0][2] == y && b[1][1] == x && b[2][0] == x) {
		return 1;
	}
	else if (b[0][2] == x && b[1][1] == y && b[2][0] == x) {
		return 1;
	}
	else if (b[0][2] == x && b[1][1] == x && b[2][0] == y) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(void)
{

	ifstream infile("tttt.in");

	ofstream outfile("tttt.out");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			char temp;
			infile >> temp;
			b[i][j] = temp;
		}
	}

	int s = 0;
	int t = 0;
	vector <pair<string, int>> vect;

	for (char x = 'A'; x <= 'Z'; x++) {
		s += singlewin(x);
	}

	for (char x = 'A'; x <= 'Z'; x++) {
		for (char y = 'A'; y <= 'Z'; y++) {
			if (x != y) {
				int test;
				test = teamwin(x, y);
				if (test > 0) {
					string a;
					a.push_back(x);
					a.push_back(y);
					for (int i = 0; i < vect.size(); i++) {
						if (conversion(vect[i].first) == conversion(a)) {
							vect[i].second++;
						}
						else if (i == vect.size() - 1) {
							vect.push_back(make_pair(a, 1));
						}
					}
					if (vect.size() == 0) {
						vect.push_back(make_pair(a, 1));
					}
				}
			}
		}
	}

	outfile << s << endl;
	t = (int)vect.size();
	outfile << t;

	outfile.close();

	return 0;
}

int main(void)
{

	for (int i = 0; i < 3; i++) {
		string temp;
		getline(cin, temp);
		for (int j = 0; j < 3; j++)
		{
			b[i][j] = temp[j];
		}
	}

	int s = 0;
	int t = 0;
	vector <pair<string, int> > vect;

	for (char x = 'A'; x <= 'Z'; x++) {
		s += singlewin(x);
	}

	for (char x = 'A'; x <= 'Z'; x++) {
		for (char y = 'A'; y <= 'Z'; y++) {
			if (x != y) {
				int test;
				test = teamwin(x, y);
				if (test > 0) {
					string a;
					a.push_back(x);
					a.push_back(y);
					for (int i = 0; i < vect.size(); i++) {
						if (conversion(vect[i].first) == conversion(a)) {
							vect[i].second++;
						}
						else if (i == vect.size() - 1) {
							vect.push_back(make_pair(a, 1));
						}
					}
					if (vect.size() == 0) {
						vect.push_back(make_pair(a, 1));
					}
				}
			}
		}
	}

	cout << s << endl;
	t = int(vect.size());
	cout << t;

	return 0;
}