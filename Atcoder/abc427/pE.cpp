#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    vector<string> v(n);
    for(auto &d : v) cin >> d;
    pair<int, int> T;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 'T') T = {i, j};
        }
    }
    vector<string> ans(n, string(m, '.'));
    v[T.first][T.second] = '.';
    map<vector<string>, int> dis;
    dis[v] = 0;
    queue<pair<int, vector<string> > > pqq;
    pqq.push({0, v});
    auto move = [&](int k, vector<string> &V) -> vector<string> {
        vector<string> nw(n, string(m, '.'));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int xx = i + dx[k], yy = j + dy[k];
                if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                nw[xx][yy] = V[i][j];
            }
        }
        return nw;
    };
    while(pqq.size()) {
        auto [w, V] = pqq.front(); pqq.pop();
        // for(auto &d : V) cout << d << '\n';
        // cout << '\n';
        for(int i = 0; i < 4; i++) {
            auto nw = move(i, V);
            if(nw[T.first][T.second] == '.') {
                if(dis.find(nw) == dis.end()) {
                    dis[nw] = w + 1;
                    pqq.push({w+1, nw});
                }
            }
        }
    }
    if(dis.find(ans) == dis.end()) cout << "-1\n";
    else cout << dis[ans] << '\n';
}