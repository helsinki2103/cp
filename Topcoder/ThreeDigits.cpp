#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define ld long double
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

class ThreeDigits {
public:
    ll mul(ll a, ll b, ll m) {
        if (b == 0) return 0;
        ll tmp = mul(a, b / 2ll, m);
        tmp = (tmp + tmp) % m;
        if (b & 1) tmp = (tmp + a) % m;
        return tmp;
    }
    ll pow(ll a, ll b, ll m) {
        if (b == 0) return 1 % m;
        ll tmp = pow(a, b / 2ll, m) % m;
        tmp = mul(tmp, tmp, m);
        if (b & 1) tmp = mul(tmp, a, m);
        return tmp;
    }
    string calculate(ll x, ll y, ll z) {
        ll t = z * 1000000ll;
        ll r = pow(x, y, t);
        r = (r * 1000ll) % t;
        ll b = r / z;
        string ans = to_string(b);
        while (ans.size() < 6) ans = "0" + ans;
        // cout << ans << '\n';
        ll c = (x == 0 ? 0 : 1);
        if (x > 1) {
            fore(i,1,y) {
                c *= x;
                if (c >= 1000ll * z) break;
            }
        }
        int idx = 2;
        if (c >= 1000ll * z) idx = 0;
        else ford(i,2,0) if (ans[i] != '0') idx = i;
        return ans.substr(idx,3-idx) + "." + ans.substr(3);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ThreeDigits t;
    cout << t.calculate(999999999, 128, 1000000);
    return 0;
}