#include <bits/stdc++.h>
using namespace std;
int logic(vector<int> cows, int k)
{
    vector<vector<int>> dp(cows.size());
    for (int i = 0; i < dp.size(); i++) {
        dp[i].resize(k);
    }

    dp[0][cows[0] % k]++;
    dp[0][cows[0] % k] %= 100000000;

    for (int i = 1; i < cows.size(); i++)
    {
        dp[i][(cows[i]) % k]++;
        dp[i][cows[i] % k] %= 100000000;
        for (int j = 0; j < k; j++)
        {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= 100000000;
            dp[i][(j + cows[i]) % k] += dp[i - 1][j];
            dp[i][(j + cows[i]) % k] %= 100000000;
        }
    }

    return dp[cows.size() - 1][0] % 100000000;
}
int main(void) {
    int n, f;
    cin >> n >> f;
    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }
    int ans = logic(cows, f);
    cout << ans;
}