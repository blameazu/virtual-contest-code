#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    set<pair<int, int> > se;
    se.insert({0, INT_MAX});
    int ans = INT_MAX;
    vector<pair<int, int> > es, in;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        auto lb = se.lower_bound(pair<int, int>{a, 0});
        int mn = INT_MAX;
        if(lb != se.end()) {
            int now = lb->first - a;
            mn = min(mn, now);
            if(lb->second > now) {
                ans -= lb->second;
                ans += now;
                es.push_back({lb->first, lb->second});
                in.push_back({lb->first, now});
            }
        }
        if(lb != se.begin()) {
            lb = prev(lb);
            int now = a - lb->first;
            mn = min(mn, now);
            if(lb->second > now) {
                ans -= lb->second;
                ans += now;
                es.push_back({lb->first, lb->second});
                in.push_back({lb->first, now});
            }
        }
        se.insert({a, mn});
        ans += mn;
        while(es.size()) {
            auto [a, b] = es.back(); es.pop_back();
            se.erase({a, b});
        }
        while(in.size()) {
            auto [a, b] = in.back(); in.pop_back();
            se.insert({a, b});
        }
        cout << ans << '\n';
    }
}