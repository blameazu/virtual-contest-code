#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("Ofast")
#define int ll
void solve() {
    int n, m; cin >> n >> m;
    // cout << n << ' ' << m << '\n';
    vector<string> v(n);
    for(auto &d : v) cin >> d;
    vector<int> dp(1<<m);
    vector<vector<int> > nxt(1<<m);
    for(int j = 0; j < (1<<m); j++) {
        for(int k = 0; k < (1<<m); k++) {
            bool ok = true;
            for(int l = 0; l < m; l++) if(((j&k)>>l&1) && ((j&k)>>(l+1)&1)) {
                ok = false;
            }
            if(ok) nxt[j].push_back(k);
        }
    }
    for(int i = 0; i < n; i++) {
        vector<int> dp2(1<<m, INT_MAX);
        for(int j = 0; j < (1<<m); j++) {
            for(auto &d : nxt[j]) {
                int tmp = 0;
                for(int k = 0; k < m; k++) tmp += (d>>k&1) != (v[i][k] == '#');
                dp2[d] = min(dp2[d], dp[j] + tmp);
            }
        }
        swap(dp, dp2);
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}