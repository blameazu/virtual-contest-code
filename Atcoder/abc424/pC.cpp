#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("Ofast")
#define int ll
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    vector<vector<int> > f(n+1);
    vector<int> in(n+1);
    queue<int> qq;
    vector<bool> vis(n+1);
    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        if(a == 0 && b == 0) {
            qq.push(i);
            vis[i] = true;
            continue;
        }
        f[a].push_back(i);
        f[b].push_back(i);
    }
    int ans = 0;
    while(qq.size()) {
        auto id = qq.front(); qq.pop();
        ans++;
        for(auto &d : f[id]) if(!vis[d]) {
            vis[d] = true;
            qq.push(d);
        }
    }
    cout << ans << '\n';
}