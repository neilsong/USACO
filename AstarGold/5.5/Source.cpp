#include <bits/stdc++.h>
using namespace std;
vector<int> h(1), w(1);
int main(void) {
    int n, l;
    cin >> n >> l;
    vector<int> dp(n + 1, INT_MAX);
    for (int i = 0; i < n; i++) {
        int hi, wi; cin >> hi >> wi;
        h.push_back(hi);
        w.push_back(wi);
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int hmx = 0;
        int wsm = 0;
        for (int j = i - 1; j >= 0; j--) {
            wsm += w[j+1];
            hmx = max(hmx, h[j +1]);
            if (wsm <= l) dp[i] = min(dp[i], hmx + dp[j]);
        }
    }
    cout << dp[n];
}