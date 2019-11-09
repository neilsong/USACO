#include <bits/stdc++.h>
using namespace std;


vector<tuple<int,int,int>> arr;
vector<int> dp;
int n;

bool sortbyarea(tuple<int, int, int> a, tuple <int, int, int> b) {
	return (get<2>(a) * get<1>(a)) > (get<2>(b) * get<1>(b));
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
	/*	tuple<int, int, int> toinsert = make_tuple( a,b,c );*/
		vector<int> permutate{ a,b,c };

		tuple<int, int, int> toins1 = make_tuple(permutate[0], min(permutate[1],permutate[2]), max(permutate[1], permutate[2]));
		arr.push_back(toins1);

		tuple<int, int, int> toins2 = make_tuple(permutate[1], min(permutate[0], permutate[2]), max(permutate[0], permutate[2]));
		arr.push_back(toins2);

		tuple<int, int, int> toins3 = make_tuple(permutate[2], min(permutate[0], permutate[1]), max(permutate[1], permutate[0]));
		arr.push_back(toins3);
		/*while (next_permutation(permutate.begin(), permutate.end())) {
			if (permutate[1] < permutate[2]) {
				tuple<int, int, int> toins = make_tuple(permutate[0], permutate[1], permutate[2]);
				arr.push_back(toins);
			}
		}*/
	}
	sort(arr.begin(), arr.end(), sortbyarea);
	for (auto i : arr) {
		dp.push_back(get<0>(i));
	}
	int ans = 0;
	for (int i = 1; i < arr.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (get<1>(arr[j]) > get<1>(arr[i]) && get<2>(arr[j]) > get<2>(arr[i]) && dp[j] + get<0>(arr[i]) > dp[i]) {
				dp[i] = dp[j] + get<0>(arr[i]);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans<< endl;
}