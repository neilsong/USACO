#include <bits/stdc++.h>
using namespace std;

int n, k;

class BigInteger {
private:
	string number;
	bool sign = 0;
public:
	string add(string number1, string number2) {
		string add = (number1.length() > number2.length()) ? number1 : number2;
		char carry = '0';
		int differenceInLength = abs((int)(number1.size() - number2.size()));

		if (number1.size() > number2.size())
			number2.insert(0, differenceInLength, '0');

		else
			number1.insert(0, differenceInLength, '0');

		for (int i = number1.size() - 1; i >= 0; --i) {
			add[i] = ((carry - '0') + (number1[i] - '0') + (number2[i] - '0')) + '0';
			if (i != 0) {
				if (add[i] > '9') {
					add[i] -= 10;
					carry = '1';
				}
				else
					carry = '0';
			}
		}
		if (add[0] > '9') {
			add[0] -= 10;
			add.insert(0, 1, '1');
		}
		return add;
	}
	const string&getNumber() {
		return number;
	}
	BigInteger() {
		number = "0";
		sign = 0;
	}

	BigInteger(string s) {
		if (isdigit(s[0])) { 
			setNumber(s);
			sign = 0;
		}
		else {
			setNumber(s.substr(1));
			sign = (s[0] == '-');
		}
	}


	BigInteger(int n) {
		stringstream ss;
		string s;
		ss << n;
		ss >> s;
		if (isdigit(s[0])) {
			setNumber(s);
		}
	}

	void setNumber(string s) {
		number = s;
	}

	BigInteger operator + (BigInteger b)
	{
		BigInteger addition;
		{
			addition.setNumber(add(getNumber(), b.getNumber()));
		}
		return addition;
	}
	BigInteger&operator += (BigInteger b)
	{
		(*this) = (*this) + b;
		return (*this);
	}
};

int main(void) {

	cin >> n >> k;
	vector<BigInteger> dp;
	dp.resize(n+1);
	dp[0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = i; j <= n; j++) {
			dp[j] += dp[j - i];
		}
	}
	cout << dp[n].getNumber();
}