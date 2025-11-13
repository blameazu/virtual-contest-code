#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int> > f(n+1);
    for(int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        f[a].push_back(b);
        f[b].push_back(a);
    }
    int ans = m;
    for(int i = 1; i < (1<<n)-1; i++) {
        int tmp = 0;
        for(int j = 0; j < n; j++) {
            for(auto &d : f[j]) if((i>>d&1) == (i>>j&1)) {
                tmp++;
            }
        }
        ans = min(ans, tmp/2);
    }
    cout << ans << '\n';
}