#include<bits/stdc++.h>

using namespace std;

int max(int a, int b, int c){
    return max(a, max(b, c));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--){
        int n, m; cin >> n >> m;
        vector<vector<int> > a(n + 2, vector<int>(m + 2));
        vector<vector<int> > dp(n + 2, vector<int>(m + 2, 0));
        int res = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++) cin >> a[i][j];
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]) + a[i][j];
            }
        }
        for(int j=1; j<=m; j++) res = max(res, dp[n][j]);
        cout << res << '\n';
    }
    return 0;
}