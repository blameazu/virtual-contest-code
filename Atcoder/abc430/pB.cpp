#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    vector<string> v(n);
    for(auto &d : v) cin >> d;
    set<vector<string> > se;
    for(int i = 0; i+m-1 < n; i++)  {
        for(int j = 0; j+m-1 < n; j++) {
            vector<string> tmp;
            for(int k = 0; k < m; k++) tmp.push_back(v[i+k].substr(j, m));
            se.insert(tmp);
        }
    }
    cout << se.size() << '\n';
}