#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const ll mod = 1e9 + 7;

class AqaAsadiMinimizes {
public:
    double getMin(vector<ll> p, ll b0, ll x, ll y, int n) {
        vector<pair<ll, int> > a(n);
        rep(i,n) {
            a[i].se = i;
            if (i < sz(p)) {
                a[i].fi = p[i];
            } else if (i == sz(p)) {
                a[i].fi = b0;
            } else {
                a[i].fi = (a[i - 1].fi % mod * x % mod) % mod;
                a[i].fi = (a[i].fi % mod + y % mod) % mod;
            }
        }
        double ans = 1e9 + 8;
        sort(a.begin(),a.end());
        // rep(i,n) cout << a[i].fi << " ";
        rep(i,n-1) {
            ans = min(ans, (double)(a[i + 1].fi - a[i].fi) / (double)abs(a[i + 1].se - a[i].se));
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    AqaAsadiMinimizes t;
    vector<ll> v = {11, 0, 30, 20, 1000};
    cout << t.getMin(v,0,0,0,5);
    return 0;
}