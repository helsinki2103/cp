#include<bits/stdc++.h>

using namespace std;
const int64_t mod = 1e6 + 7;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int64_t x; cin >> x;
        int64_t ans = x * (x + 1);
        ans %= mod;
        ans += x * (x + 1) / 2;
        ans -= x;
        ans %= mod;
        ans += mod;
        ans %= mod;
        cout << ans << '\n';
    }
    return 0;
}