#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;

int c[N], memo[N];
int n, m;

int calc(int rem){
    if (rem==0) return 0;
    if (rem<0) return 10000;
    if (memo[rem]!=-1) return memo[rem];
    memo[rem] = 10000;
    for(int i=0; i<n; i++){
        memo[rem] = min(memo[rem], 1 + calc(rem - c[i]));
    }
    return memo[rem];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> c[i];
    memset(memo,-1,sizeof memo);
    cout << calc(m);
    return 0;
}