#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << a*b * (d/(b+c)) + min(b, d%(b+c)) * a << '\n';
}