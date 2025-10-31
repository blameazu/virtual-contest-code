#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    vector<vector<int> > f(n+1);
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        f[a].push_back(b);
        f[b].push_back(a);
    }
    vector<pair<int, int> > dep(n+1);
    auto dfs = [&](auto dfs, int id, int pa, int r, int DEP = 0) -> pair<int, int> {
        pair<int, int> re = {0, id};
        dep[id] = max(dep[id], pair<int,int>{DEP, r});
        for(auto &d : f[id]) if(d != pa) {
            auto [a, b] = dfs(dfs, d, id, r, DEP+1);
            re = max(re, pair<int, int>{a+1, b});
        }
        return re;
    };
    auto [a, b] = dfs(dfs, 1, 1, 1);
    auto [c, d] = dfs(dfs, b, b, b);
    dfs(dfs, d, d, d);
    for(int i = 1; i <= n; i++) cout << dep[i].second << '\n';
}