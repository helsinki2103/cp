#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int x = sqrt(n);
    int ans = 0;
    // O(sqrt(n)) solution
    for(int i=1; i<x; i++) ans += n/i;
    ans -= (x - 1) * (x - 2) / 2;
    ans += n/x - x + 1;
    cout << ans << '\n';
    return 0;   
}