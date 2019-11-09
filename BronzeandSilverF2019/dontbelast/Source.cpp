#include <iostream>
#include <bits/stdc++.h>
using namespace std;




int main()
{
	ifstream fin("notlast.in");
	ofstream fout("notlast.out");
	int N, p;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int g = 0;
	string k;
	fin >> p;
	while (p > 0)
	{
		fin >> k >> N;
		if (k == "Bessie")
		{
			a = a + N;
		}
		if (k == "Elsie")
		{
			b = b + N;
		}
		if (k == "Daisy")
		{
			c = c + N;
		}
		if (k == "Gertie")
		{
			d = d + N;
		}
		if (k == "Annabelle")
		{
			e = e + N;
		}
		if (k == "Maggie")
		{
			f = f + N;
		}
		if (k == "Henrietta")
		{
			g = g + N;
		}
		p--;
	}
	int w[7];
	int x;
	w[0] = a;
	w[1] = b;
	w[2] = c;
	w[3] = d;
	w[4] = e;
	w[5] = f;
	w[6] = g;
	sort(w, w + 7);
	int mind2ind = 0;
	for (int i = 0; i < 7; i++) {
		if (w[i] != w[0]) {
			mind2ind = i;
			break;
		}
	}
	if (w[mind2ind] == w[mind2ind+1])
	{
		fout << "Tie" << endl;
	}
	else if (w[mind2ind] == a)
	{
		fout << "Bessie" << endl;
	}
	else if (w[mind2ind] == b)
	{
		fout << "Elsie" << endl;
	}
	else if (w[mind2ind] == c)
	{
		fout << "Daisy" << endl;
	}
	else if (w[mind2ind] == d)
	{
		fout << "Gertie" << endl;
	}
	else if(w[mind2ind] == e)
	{
		fout << "Annabelle" << endl;
	}
	else if (w[mind2ind] == f)
	{
		fout << "Maggie" << endl;
	}
	else if (w[mind2ind] == g)
	{
		fout << "Henrietta" << endl;
	}
}