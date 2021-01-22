#include<bits/stdc++.h>

using namespace std;

vector<int> a;
int l, n;
int memo[105][105];

int calc(int l, int r){
    if (l+1>=r) return 0;
    if (memo[l][r]!=-1) return memo[l][r];
    memo[l][r] = 10000;
    for(int i=l+1; i<r; i++) memo[l][r] = min(memo[l][r], calc(l, i) + calc(i, r) + a[r] - a[l]);
    return memo[l][r];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> l >> n;
    a.resize(n + 2);
    a[0] = 0; a[n + 1] = l;
    for(int i=1; i<=n; i++) cin >> a[i];
    memset(memo,-1,sizeof memo);
    cout << calc(0, n + 1);
    return 0;
}