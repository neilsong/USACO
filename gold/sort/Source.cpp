#include <bits/stdc++.h>
using namespace std;
//fenwick tree from GeeksforGeeks
const int MAX_VAL = 1000001;

/* Updates element at index 'i' of BIT. */
void update(int i, int add, vector<int>& BIT)
{
	while (i > 0 && i < BIT.size())
	{
		BIT[i] += add;
		i = i + (i & (-i));
	}
}

/* Returns cumulative sum of all elements of
   fenwick tree/BIT from start upto and
   including element at index 'i'. */
int sum(int copy, vector<int>& BIT)
{
	int i = copy;
	int ans = 0;
	while (i > 0)
	{
		ans += BIT[i];
		i = i - (i & (-i));
	}

	return ans;
}

// Returns lower bound for k in BIT. 
int findKthSmallest(int k, vector<int>& BIT)
{
	// Do binary search in BIT[] for given 
	// value k. 
	int l = 0;
	int h = BIT.size();
	while (l < h)
	{
		int mid = (l + h) / 2;
		if (k <= sum(mid, BIT))
			h = mid;
		else
			l = mid + 1;
	}

	return l;
}

// Insert x into BIT. We masically increment 
// rank of all elements greater than x. 
void insertElement(int x, vector<int>& BIT)
{
	update(x, 1, BIT);
}

// Delete x from BIT. We masically decreases 
// rank of all elements greater than x. 
void deleteElement(int x, vector<int>& BIT)
{
	update(x, -1, BIT);
}

// Returns rank of element. We basically 
// return sum of elements from start to 
// index x. 
int findRank(int x, vector<int>& BIT)
{
	return sum(x, BIT);
}

int main(void) {
	ifstream cin("sort.in");
	ofstream cout("sort.out");

	int n; cin >> n;
	vector<int> arr(MAX_VAL);
	vector<pair<int,int>> sorted(1);

	int ans = 1;

	for (int i = 1; i <= n; i++) {
		int ins;
		cin >> ins;
		sorted.push_back({ ins, i });
	}
	sort(sorted.begin(), sorted.end());
	for (int i = 1; i <= n; i++) {
		insertElement(sorted[i].second, arr);
		int temp = i-findRank(i, arr);
		ans = max(ans, temp);
	}
	cout << ans<< endl;
}