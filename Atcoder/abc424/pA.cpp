#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("sse,sse2,sse3,sse3,sse4.1,sse4.2,avx,avx2,popcnt")
#define ll long long
#define int ll
void presolve() {
	
}
void solve() {
	int a, b, c; cin >> a >> b >> c;
	if(a == b || b == c || a == c) cout << "Yes\n";
	else cout << "No\n";
}
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	presolve();
	int t = 1;
	// cin >> t;
	while(t--) solve();
}