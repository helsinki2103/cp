#include<bits/stdc++.h>

using namespace std;
const int N = 5e3 + 5;

int dp[N][N];

int main()
{
    freopen("input.txt","r",stdin);
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s[i]==t[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[n][m] << '\n';
}