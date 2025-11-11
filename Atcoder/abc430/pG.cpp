#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
struct Seg {
    vector<pair<int, int> > tr;
    vector<array<bool, 64> > allz, allo;
    Seg(int n) : tr((n<<4)+87), allz((n<<4)+87), allo((n<<4)+87) {}
    void build(int l, int r, int id = 1) {
        for(int i = 1; i <= 60; i++) allz[id][i] = true, allo[id][i] = false;
        if(l == r) {
            return tr[id] = {0, 1}, void();
        }
        int mid = l+r>>1;
        build(l, mid, id<<1);
        build(mid+1, r, id<<1|1);
        tr[id] = {0, r-l+1};
    }
    void upd(int ql, int qr, int x, int qx, int l, int r, int id = 1) {
        if(ql <= l && r <= qr) {
            if(x == 0) {
                if(allo[id][qx]) {
                    allz[id][qx] = true; allo[id][qx] = false;
                    tr[id].first--;
                    return;
                }
                if(allz[id][qx]) return;
            } else {
                if(allz[id][qx]) {
                    allo[id][qx] = true; allz[id][qx] = false;
                    tr[id].first++;
                    return;
                }
                if(allo[id][qx]) return;
            }
        }
        int mid = l+r>>1;
        if(ql <= mid) upd(ql, qr, x, qx, l, mid, id<<1);
        if(qr > mid) upd(ql, qr, x, qx, mid+1, r, id<<1|1);
        tr[id] = tr[id<<1];
        if(tr[id<<1|1].first > tr[id].first) tr[id] = tr[id<<1|1];
        else if(tr[id<<1|1].first == tr[id].first) tr[id].second += tr[id<<1|1].second;
    }
    pair<int, int> qry(int ql, int qr, int l, int r, int id = 1) {
        if(ql <= l && r <= qr) {
            return tr[id];
        }
        pair<int, int> re = {0, 0};
        int mid = l+r>>1;
        if(ql <= mid) {
            auto [a, b] = qry(ql, qr, l, mid, id<<1);
            if(a == re.first) re.second += b;
            if(a > re.first) re = {a, b};
        }
        if(qr > mid) {
            auto [a, b] = qry(ql, qr, l, mid, id<<1);
            if(a == re.first) re.second += b;
            if(a > re.first) re = {a, b};
        }
        return re;
    }
};
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, q; cin >> n >> q;
    Seg seg(n);
    seg.build(1, n);
    while(q--) {
        int c, l, r; cin >> c >> l >> r;
        if(c == 1) {
            int x; cin >> x;
            seg.upd(l, r, 1, x, 1, n);
        } else if(c == 2) {
            int x; cin >> x;
            seg.upd(l, r, 0, x, 1, n);
        } else {
            auto [a, b] = seg.qry(l, r, 1, n);
            cout << a << ' ' << b << '\n';
        }
    }
}