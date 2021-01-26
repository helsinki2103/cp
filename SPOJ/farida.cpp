#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    for(int iTest=1; iTest<=nTest; iTest++){
        int n; cin >> n;
        vector<int64_t> a(n + 1), dp(n + 1, 0);
        for(int i=1; i<=n; i++) cin >> a[i];
        int64_t res = 0;
        for(int i=1; i<=n; i++){
            dp[i] = a[i];
            for(int j=i-2; j>=1; j--) dp[i] = max(dp[i], dp[j] + a[i]);
            res = max(res, dp[i]);
        }
        cout << "Case " << iTest << ": " << res << '\n';
    }
    return 0;
}