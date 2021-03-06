#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, M;

vector <string> a;

int dr[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

char get(int r, int c) {
	if (r < 0 || N <= r || c < 0 || M <= c) {
		return '_';
	}
	return a[r][c];
}

int main(void)
{
	ifstream fin("moocrypt.in");
	ofstream fout("moocrypt.out");

	
	fin >> N >> M;

	int c = 0;


	for (int i = 0; i < N; i++) {
		string b;
		fin >> b;
		a.push_back(b);
	}

	for (char mcr = 'A'; mcr <= 'Z'; mcr++) {
		if (mcr == 'M') {
			continue;
		}
		for (char ocr = 'A'; ocr <= 'Z'; ocr++) {
			if (ocr == 'O' || ocr == mcr) {
				continue;
			}
			int r = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (a[i][j] != mcr) {
						continue;
					}
					for (int k = 0; k < 8; k++) {
						if (get(i + 1 * dr[k], j + 1 * dc[k]) == ocr && get(i + 2 * dr[k], j + 2 * dc[k]) == ocr) {
							r ++ ;
						}
					}
				}
			}
			c = max(c, r);
		}
	}

	fout << c << endl;

	return 0;
}