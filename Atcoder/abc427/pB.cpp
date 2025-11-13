#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    vector<int> dp(n+1);
    vector<int> v(n+1);
    dp[1] = 1;
    v[1] = 1;
    for(int i = 2; i <= n; i++) {
        v[i] = dp[i-1];
        dp[i] += dp[i-1];
        for(auto &d : to_string(v[i]))
            dp[i] += d-'0';
        // cout << dp[i] << " \n"[i==n];
    }
    cout << dp[n] << '\n';
}