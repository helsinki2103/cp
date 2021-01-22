/*
Task: 1415C
Date: Dec 28, 2020
Author: aLittleLove (Minh Vu)
*/

#include<bits/stdc++.h>
const int inf = 1e9;
using namespace std;

void Solve()
{
    int n, p, k; cin >> n >> p >> k;
    string s; cin >> s;
    s = ' ' + s;
    int x, y; cin >> x >> y;
    vector<int> dp(n + 1, inf); dp[0] = 0;
    for (int i=p; i<=n; i++)
    {
        dp[i] = min(dp[i], (i - p) * y + (s[i]=='1' ? 0 : x));
        if (i>k) dp[i] = min(dp[i], dp[i - k] + (s[i]=='1' ? 0 : x));
    }
    int res = inf;
    for (int i=n; i>=n-k+1; i--) res = min(res, dp[i]);
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();
    return 0;
}