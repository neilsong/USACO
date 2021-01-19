#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ifstream cin("moobuzz.in");
	ofstream cout("moobuzz.out");
	long long n;
	cin >> n;
	n--;


	vector<long long> sequence{ 1, 2, 4, 7, 8, 11, 13, 14, 16, 17, 19, 22, 23, 26, 28, 29};



	long long ind = n % 16;
	cout << (long long) sequence[ind] + (long long) ((n / 16) * 30);


/*
	1 2 4 7 8 11 13 14 16 17 19 22 23 26 28 29
	{1 2 3 1 3           2 1 2 1 2 3                1  3 2 1 2}
	31 32 34 37 38   41 43 44 46 47 49 52 53 56 58 59
	1 2 3 1 3           2 1 2 1 2 3    1 3 2 1 2

	3 6 9 12 15 18 21 24 27 3*/




	//cout << ans;
}