#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, m, k; cin >> n >> m >> k;
        string s; cin >> s;
        vector<vector<int> > f(n+1);
        for(int i = 1; i <= m; i++) {
            int a, b; cin >> a >> b;
            f[a].push_back(b);
        }
        vector<vector<int> > dp(n+1, vector<int> ((k<<1)+1));
        for(int i = 1; i <= n; i++) {
            dp[i][0] = s[i-1] == 'A';
        }
        for(int K = 1; K <= (k<<1); K++) {
            for(int i = 1; i <= n; i++) {
                bool ok = true;
                for(auto &d : f[i]) {
                    ok = ok && dp[d][K-1];
                }
                dp[i][K] = !ok;
            }
        }
        cout << (dp[1][(k<<1)] ? "Alice\n" : "Bob\n");
    }
}