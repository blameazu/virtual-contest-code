#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, k; cin >> n >> k;
	vector<int> v(n+1), w(n+1);
	int ans = 0;
	for(int i = 1; i <= n; i++) cin >> v[i];
	for(int i = 1; i <= n; i++) cin >> w[i], ans += v[i] * w[i];
	priority_queue<pair<int, int> > pqq;
	for(int i = 1; i <= n; i++) {
		pqq.push({(v[i]-v[i]/2) * w[i], i});
		v[i] /= 2;
	}
	while(pqq.size()) {
		auto [a, b] = pqq.top(); pqq.pop();
		ans -= a;
		// cout << a << ' ' << b << '\n';
		k--;
		if(k == 0) break;
		if(v[b] == 0) continue;
		pqq.push({(v[b] - v[b]/2)*w[b], b});
		v[b] /= 2;
	}
	cout << ans << '\n';
}