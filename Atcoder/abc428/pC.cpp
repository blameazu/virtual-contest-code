#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    vector<int> stk;
    vector<bool> ok{true};
    int q; cin >> q;
    int A = 0, B = 0;
    int pre = 0;
    int OK = 0;
    while(q--) {
        int c; cin >> c;
        if(c == 1) {
            char a; cin >> a;
            int b = (a == '(' ? 1 : -1);
            pre += b;
            if(pre < 0) OK++;
            if(b == 1) A++;
            else B++;
            if(A != B) ok.push_back(false);
            else if(OK) ok.push_back(false);
            else {
                ok.push_back(true);
            }
            stk.push_back(b);
        } else {
            if(pre < 0) OK--;
            if(stk.back() == 1) A--;
            else B--;
            pre -= stk.back();
            stk.pop_back();
            ok.pop_back();
        }
        // cout << pre << ' ';
        cout << (ok.back() ? "Yes\n" : "No\n");
    }
}