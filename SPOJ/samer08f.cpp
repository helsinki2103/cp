#include<bits/stdc++.h>

using namespace std;

int64_t dp[105];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    dp[0] = 0;
    for(int i=1; i<=100; i++) dp[i] = dp[i - 1] + i * i;
    while (cin >> n && n){
        cout << dp[n] << '\n';
    }
    return 0;
}