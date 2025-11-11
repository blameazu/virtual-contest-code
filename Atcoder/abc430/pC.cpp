#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, A, B; cin >> n >> A >> B;
    string s; cin >> s;
    s = '#' + s;
    vector<int> preA{0}, preB{0};
    int L = 0, R = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        preA.push_back(preA.back() + (s[i] == 'a'));
        preB.push_back(preB.back() + (s[i] == 'b'));
        while(R < i && preA[i] - preA[R] >= A) R++;
        while(L <= R && preB[i] - preB[L] >= B) L++;
        ans += max(0LL, R-L);
    }
    cout << ans << '\n';
}