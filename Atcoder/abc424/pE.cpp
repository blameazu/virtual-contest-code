#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("Ofast")
#define int ll
void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<array<long double, 35> > v(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i][0];
        for(int j = 1; j <= 32; j++) {
            v[i][j] = v[i][j-1]/2;
        }
    }
    auto cnt = [&](long double id) -> int {
        int re = 0;
        for(int i = 1; i <= n; i++) {
            int j = 0;
            while(j <= 32 && v[i][j] >= id) j++;
            j--;
            re += (1<<j);
        }
        return re;
    };
    long double l = 0, r = 1e9;
    while(l < r) {
        long double mid = l+r/2;
        if(cnt(mid) >= k+n-x) r = mid;
        else l = mid+1e-9;
    }
    
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}