#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#pragma GCC optimize("Ofast")
const ll neg_inf = 1e18;
#define vi vector<ll>
#define vii vector<vi>
vii mul(const vii &a, const vii &b) {
	vii re(a.size(), vi(b[0].size(), neg_inf));
	for(int i = 0; i < (int)a.size(); i++)
		for(int j = 0; j < (int)b[0].size(); j++)
			for(int k = 0; k < (int)a[0].size(); k++) {
				ll A = a[i][k];
				ll B = b[k][j];
				if(!(A == neg_inf || B == neg_inf))
					re[i][j] = min(re[i][j], A + B);
			}
	return re;
}
vii BS(4, vi(4, neg_inf));
struct Seg {
	int n, m;
	vector<vii> tr;
	Seg(int x, int y) : n(x), m(y), tr((x<<2)+87, BS) {}
	vii qry(int ql, int qr, int l, int r, int id = 1) {
		if(ql <= l && r <= qr) return tr[id];
		int mid = l+r>>1;
        auto re = BS;
		if(ql <= mid) re = mul(re, qry(ql, qr, l, mid, id<<1));
		if(qr > mid) re = mul(re, qry(ql, qr, mid+1, r, id<<1|1));
		return re;
	}
	void upd(int x, int l, int r, const vii &v, int id = 1) {
		if(l == r) return tr[id] = v, void();
		int mid = l+r>>1;
		if(x <= mid) upd(x, l, mid, v, id<<1);
		else upd(x, mid+1, r, v, id<<1|1);
		tr[id] = mul(tr[id<<1], tr[id<<1|1]);
	}
};
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    for(int i = 0; i < 4; i++) BS[i][i] = 0;
    int n; cin >> n;
    vector<int> v(n+1);
    for(int j = 0; j < 3; j++) {
        string s; cin >> s;
        for(int i = 1; i <= n; i++) if(s[i-1] == '.')
            v[i] |= (1<<j);
    }
    auto build_matrix = [&](int A, int B) -> vii {
        vii re(4, vi(4, neg_inf));
        re[3][3] = 0;
        for(int i = 0; i < 3; i++) if((A>>i&1) && (B>>i&1)) re[i][i] = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if((A>>i&1) && (B>>j&1)) {
                    if(i-1 >= 0 && (A>>(i-1)&1)) {
                        re[i-1][j] = min(re[i-1][j], re[i][j] + 1);
                    }
                    if(i+1 < 3 && (A>>(i+1)&1)) {
                        re[i+1][j] = min(re[i+1][j], re[i][j] + 1);
                    }
                }
                if((B>>i&1) && (A>>j&1)) {
                    if(i-1 >= 0 && (B>>(i-1)&1)) {
                        re[j][i-1] = min(re[j][i-1], re[j][i] + 1);
                    }
                    if(i+1 < 3 && (B>>(i+1)&1)) {
                        re[j][i+1] = min(re[j][i+1], re[j][i] + 1);
                    }
                }
            }
        }
        return re;
    };
    Seg seg(n, 4);
    for(int i = 1; i < n; i++) {
        seg.upd(i, 1, n, build_matrix(v[i], v[i+1]));
    }
    int q; cin >> q;
    vii bs = {{0, neg_inf, neg_inf, 0}};
    while(q--) {
        int a, b; cin >> a >> b;
        swap(a, b);
        v[a] ^= (1<<(b-1));
        if(a >= 2) seg.upd(a-1, 1, n, build_matrix(v[a-1], v[a]));
        if(a <= n-1) seg.upd(a, 1, n, build_matrix(v[a], v[a+1]));
        vii ans = mul(bs, seg.qry(1, n-1, 1, n));
        int Ans = INT_MAX;
        for(int i = 0; i < 3; i++) Ans = min(Ans, ans[0][i]);
        if(Ans == INT_MAX) cout << "-1\n";
        else cout << Ans << '\n';
    }
}