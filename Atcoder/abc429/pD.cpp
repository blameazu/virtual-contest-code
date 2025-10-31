#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m, C; cin >> n >> m >> C;
    vector<int> v(n);
    for(auto &d : v) cin >> d, d++;
    sort(v.begin(), v.end());
    vector<pair<int, int> > tmp;
    for(int i = 0; i < n;) {
        int j = i+1;
        while(j < n && v[j] == v[i]) j++;
        tmp.push_back({v[i], j-i});
        i = j;
    }
    vector<int> Pre{0};
    for(auto &[a, b] : tmp) Pre.push_back(Pre.back() + b);
    for(auto &[a, b] : tmp) Pre.push_back(Pre.back() + b);
    int ans = 0, pre = 0;
    for(int i = 0; i < tmp.size(); i++) {
        auto [a, b] = tmp[i];
        // cout << a << ' ' << b << '\n';
        auto [c, d] = tmp[(i+tmp.size()-1)%(tmp.size())];
        ans += (*lower_bound(Pre.begin(), Pre.end(), pre + C) - pre) * ((a-c+m)%m == 0 ? m : (a-c+m)%m);
        pre += b;
        // cout << *lower_bound(Pre.begin(), Pre.end(), pre + C) - pre << ' ' << (a-c+m)%m << '\n';
    }
    cout << ans << '\n';
}