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
        f[a].push_back(b);
        f[b].push_back(a);
    }
    string s; cin >> s;
    vector<array<int, 3> > ans(n+1, {-1, -1, 0});
    queue<array<int, 3> > qq;
    for(int i = 1; i <= n; i++) if(s[i-1] == 'S') {
        ans[i] = {i, -1, 0};
        qq.push({i, i, 0});
    }
    while(qq.size()) {
        auto [now, id, w] = qq.front(); qq.pop();
        // cout << now << ' ' << id << ' ' << w << ' ' << ans[now][2] << '\n';
        for(auto &d : f[now]) {
            if(ans[d][0] == -1) {
                ans[d][0] = id;
                ans[d][2] += w+1;
                qq.push({d, id, w+1});
            } else if(ans[d][1] == -1 && ans[d][0] != id) {
                ans[d][1] = id;
                ans[d][2] += w+1;
                qq.push({d, id, w+1});
            }
        }
    }
    for(int i = 1; i <= n; i++) if(s[i-1] == 'D') cout << ans[i][2] << '\n';
}