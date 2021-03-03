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

struct Edge {
    int u, v, w;
    bool operator < (const Edge &oth) const {
        return w > oth.w;
    }
};

class TheSocialNetwork {
public:
    int pa[305], weight[305];
    int root(int x) {
        return (pa[x] == x ? x : pa[x] = root(pa[x]));
    }
    ll pow(ll a, ll b) {
        if (b == 0) return 1;
        ll tmp = pow(a, b / 2ll) % mod;
        if (b & 1) return (tmp * tmp * a % mod) % mod;
        return (tmp * tmp) % mod;
    }
    ll minimumCut(int n, int m, vector<int> u, vector<int> v, vector<int> l) {
        vector<Edge> e;
        rep(i,n) pa[i] = i, weight[i] = 1;
        rep(i,m) {
            e.push_back({u[i] - 1, v[i] - 1, l[i]});
        }
        sort(e.begin(), e.end());
        ll ans = 0;
        rep(i,m) {
            int u = root(e[i].u);
            int v = root(e[i].v);
            if (u == v) continue;
            if (weight[u] < weight[v]) swap(u, v);
            if (weight[u] + weight[v] < n) {
                pa[v] = u;
                weight[u] += weight[v];
            } else {
                ans = (ans % mod + pow(2, e[i].w) % mod) % mod;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    TheSocialNetwork t;
    vector<int> u = {1, 1, 1, 2, 2, 3, 3};
    vector<int> v = {5, 3, 2, 5, 3, 5, 4};
    vector<int> l = {1, 8, 2, 3, 4, 6, 9};
    cout << t.minimumCut(5, 7, u, v, l);
    return 0;
}