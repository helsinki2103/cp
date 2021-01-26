#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--){
        string s; cin >> s;
        int n = s.size();
        s = ' ' + s;
        int res = 0;
        vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));
        for(int i=n; i>=1; i--){
            for(int j=1; j<=n; j++){
                //if (i<j) continue;
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                if (s[i]==s[j]) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
                res = max(res, dp[i][j]);
            }
        }
        cout << n - res << '\n';
    }
    return 0;
}