#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    map<string, int> mp;
    int mx = 0;
    for(int i = 0; i+m-1 < n; i++) {
        mp[s.substr(i, m)]++;
        mx = max(mx, mp[s.substr(i, m)]);
    }
    cout << mx << '\n';
    for(auto &[a, b] : mp) if(b == mx)
        cout << a << ' ';
    cout << '\n';
}