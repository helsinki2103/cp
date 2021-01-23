#include<bits/stdc++.h>

using namespace std;

map<int64_t, int64_t> memo;

int64_t calc(int64_t n){
    if (n<12) return n;
    if (memo[n]!=0) return memo[n];
    memo[n] = max(n, calc(n/2) + calc(n/3) + calc(n/4));
    return memo[n];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int64_t n; 
    while (cin>>n){
        cout << calc(n) << '\n';
    }
    return 0;
}