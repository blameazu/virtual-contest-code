#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("Ofast")
#define int ll
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> cnt(n+1, m);
    vector<int> ans;
    for(int i = 1; i <= k; i++) {
        int a, b; cin >> a >> b;
        cnt[a]--;
        if(cnt[a] == 0) ans.push_back(a);
    }
    for(auto &d : ans) cout << d << ' ';
    cout << '\n';
    
}