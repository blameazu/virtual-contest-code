#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string a, b; cin >> a >> b;
        a += a;
        const int n = b.size();
        vector<int> kmp(n);
        for(int i = 1, j = 0; i < n; kmp[i++] = j) {
            while(j && b[i] != b[j]) {
                j = kmp[j-1];
            }
            if(b[i] == b[j]) j++;
        }
        int ans = -1;
        for(int i = 0, j = 0; i < n+n; i++) {
            while(j && a[i] != b[j]) j = kmp[j-1];
            if(a[i] == b[j]) j++;
            if(j == n) {
                ans = i-n+1;
                break;
            }
        }
        cout << ans << '\n';
        // for(int i = 0; i < n; i++) cout << kmp[i] << " \n"[i==n-1];
    }
}