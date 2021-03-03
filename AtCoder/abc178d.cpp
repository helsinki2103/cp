#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define fore(i,a,b) for (int i = (a); i <= (b); i++)
#define ford(i,a,b) for (int i = (a); i >= (b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const ll mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll s; cin >> s;
    vector<ll> dp(s + 1, 0);
    dp[0] = 1;
    fore(i,3,s) {
        dp[i] = (dp[i - 1] % mod + dp[i - 3] % mod) % mod;
    }
    cout << dp[s];
    return 0;
}