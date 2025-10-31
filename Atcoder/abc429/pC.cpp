#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        mp[a]++;
    }
    int ans = 0;
    for(auto &[a, b] : mp) ans += b*(b-1)/2 * (n-b);
    cout << ans << '\n';
}