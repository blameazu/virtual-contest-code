#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    vector<map<pair<int, int> , int> > dp(n+1);
    for(int i = 1; i <= n; i++) {
        dp[i][{v[i], (i==n/2-1) || (i==n/2)}] = 1;
    }
    vector<map<int, int> > V(2);
    V[0][0] = 1;
    // V[1][0] = 1;
    int ans = 1;
    for(int i = 1; i < n/2; i++) {
        for(auto &[A, b] : dp[i]) {
            auto &[a, c] = A;
            for(int j = i+2; j < n/2; j++) {
                dp[j][{(a+v[j])%m, c||(j==n/2-1)}] += b;
            }
            V[c][a] += b;
            if(a == 0) ans += b;
        }
    }
    for(int i = n/2; i <= n; i++) {
        for(auto &[A, b] : dp[i]) {
            auto &[a, c] = A;
            for(int j = i+2; j <= n; j++) {
                dp[j][{(a+v[j])%m, c}] += b;
            }
            if(!c) ans += V[1][(m-a)%m] * b;
            ans += V[0][(m-a)%m]*b;
        }
    }
    cout << ans << '\n';
}