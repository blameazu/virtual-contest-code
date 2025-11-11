#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n; cin >> n;
	vector<string> v(n);
	for(auto &d : v) cin >> d;
	vector<vector<int> > dp(n+1, vector<int> (n+1)), pre(n+1, vector<int> (n+1));
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + (v[i-1][j-1]-'0');
			if(v[i-1][j-1] != '0') {
				dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
				ans = max(ans, pre[i][j] - pre[i-dp[i][j]][j] - pre[i][j-dp[i][j]] + pre[i-dp[i][j]][j-dp[i][j]]);
			}
		}
	cout << ans << '\n';
}
/*
		(c, d)
(a, b)
*/