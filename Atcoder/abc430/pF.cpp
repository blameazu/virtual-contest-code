#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        s = '#' + s;
        vector<vector<int> > f(n+1), g(n+1);
        for(int i = 1; i < n; i++) {
            if(s[i] == 'L') {
                f[i].push_back(i+1);
                g[i+1].push_back(i);
            } else {
                g[i].push_back(i+1);
                f[i+1].push_back(i);
            }
        }
        vector<int> Fcnt(n+1), Gcnt(n+1);
        for(int T = 0; T < 2; T++, swap(f, g), swap(Fcnt, Gcnt)) {
            vector<int> in(n+1);
            for(int i = 1; i <= n; i++) {
                for(auto &d : f[i]) in[d]++;
            }
            queue<int> qq;
            for(int i = 1; i <= n; i++) if(!in[i]) {
                qq.push(i);
            }
            while(qq.size()) {
                auto id = qq.front(); qq.pop();
                for(auto &d : f[id]) {
                    in[d]--;
                    Fcnt[d] += Fcnt[id] + 1;
                    if(!in[d]) {
                        qq.push(d);
                    }
                }
            }
        }
        swap(Fcnt, Gcnt);
        vector<int> D(n+2);
        for(int i = 1; i <= n; i++) {
            D[Fcnt[i]+1]++;
            D[min(n+1, Fcnt[i]+1+n-(Gcnt[i]+Fcnt[i]+1)+1)]--;
            // cout << i << " : " << Fcnt[i]+1 << ' ' << Fcnt[i]+1+n-(Gcnt[i]+1)+1 << '\n';
        }
        // for(int i = 1; i <= n; i++) cout << Gcnt[i] << " \n"[i==n];
        for(int i = 1; i <= n; i++) {
            D[i] += D[i-1];
            cout << D[i] << " \n"[i==n];
        }
    }
}