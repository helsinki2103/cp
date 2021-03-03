#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define fore(i,a,b) for (int i = (a); i <= int(b); i++)
#define ford(i,a,b) for (int i = (a); i >= (b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    vector<int> prime(mx + 1, 0);
    int g = 0;
    bool f = 1;
    fore(i,1,mx) prime[i] = i;
    for (int i = 2; i * i <= mx; i++) {
        if (prime[i] == i) {
            for (int j = 1; j * i <= mx; j++) prime[i * j] = i;
        }
    }

    rep(i,n) g = __gcd(g, a[i]);
    vector<int> cnt(mx + 1, 0);
    rep(i,n) {
        if (a[i] == 1) continue;
        cnt[prime[a[i]]]++;
        int cur = a[i];
        while (cur % prime[a[i]] == 0) cur /= prime[a[i]];
        if (cur > 1) cnt[cur]++;
    }
    fore(i,2,mx) f &= cnt[i] <= 1;
    if (g == 1 && f) cout << "pairwise coprime";
    else if (g == 1 && !f) cout << "setwise coprime";
    else cout << "not coprime";
    return 0;
}