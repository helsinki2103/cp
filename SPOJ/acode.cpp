#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    string s;
    while (cin>>s){
        if (s[0]=='0') break;
        int n = s.size();
        s = ' ' + s;
        vector<int64_t> dp(n + 1, 0);
        dp[0] = 1;
        bool f = 0;
        for(int i=1; i<=n; i++){
            if (i<n && s[i + 1]=='0') s[i] = 'x', s[i + 1] = 'x';
            dp[i] = dp[i - 1];
            if (s[i]=='x') continue;
            int num = (int)(s[i - 1] - '0') * 10 + (int)(s[i] - '0');
            if (num>=11 && num<=26){
                dp[i] = max(dp[i], dp[i - 2] + dp[i - 1]);
            }
        }
        cout << dp[n] << '\n';
    }
    return 0;
}