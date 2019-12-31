#include <bits/stdc++.h>
using namespace std;
#define MOD 97654321
vector<vector<vector<int>>> dp;
int u, l, p;
vector<int> f, s;
int main(void) {
    cin >> u >> l >> p;
    vector<vector<int>> model;
    model.assign(l + 1, vector<int>(52, 0));
    dp.assign(u + 1, model);
    for (int i = 0; i < 26; i++) dp[1][0][i]++;
    for (int i = 26; i < 52; i++) dp[0][1][i]++;
    f.resize(p); s.resize(p);
    for (int i = 0; i < p; i++) {
        string pair;
        cin >> pair;
        f[i] = pair[0] >= 'A' && pair[0] <= 'Z' ? pair[0] - 'A' : 26+ pair[0] - 'a';
        s[i] = pair[1] >= 'A' && pair[1] <= 'Z' ? pair[1] - 'A' : 26+pair[1] - 'a';
    }
    for (int i = 0; i <= u; i++){
        for (int j = 0; j <= l; j++) {
            for (int k = 0; k < p; k++) {
                if (s[k] < 26 && i > 0) {
                    dp[i][j][s[k]] = (dp[i][j][s[k]] + dp[i - 1][j][f[k]]);
                    dp[i][j][s[k]] %= MOD;
                }
                else if (s[k] >= 26 && j > 0) {
                    dp[i][j][s[k]] = (dp[i][j][s[k]] + dp[i][j - 1][f[k]]);
                    dp[i][j][s[k]] %= MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 52; i++) { 
        ans += dp[u][l][i]; 
        ans %= MOD; 
    }
    cout << ans << endl;
}
