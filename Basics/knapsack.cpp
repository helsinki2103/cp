#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;

int v[N], w[N];
int memo[N][N];
int n, S;

int calc(int id, int rem){
    if (id==n) return 0;
    if (rem==0) return 0;
    if (memo[id][rem]!=-1) return memo[id][rem];
    if (w[id] > rem) memo[id][rem] = calc(id + 1, rem);
    else if (w[id] <= rem) memo[id][rem] = max(calc(id + 1, rem), v[id] + calc(id + 1, rem - w[id]));
    return memo[id][rem];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n >> S;
    for(int i=0; i<n; i++) cin >> v[i];
    for(int i=0; i<n; i++) cin >> w[i];
    memset(memo,-1,sizeof memo);
    cout << calc(0, S);
    return 0;
}