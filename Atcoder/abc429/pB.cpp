#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m; cin >> n >> m;
    int sum = 0;
    vector<int> v(n);
    for(auto &d : v) cin >> d, sum += d;
    for(auto &d : v) if(sum -d == m) {
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
}