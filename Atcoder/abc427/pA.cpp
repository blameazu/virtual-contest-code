#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    string s; cin >> s;
    cout << s.substr(0, s.size()/2) << s.substr(s.size()/2+1, s.size()) << '\n';
}