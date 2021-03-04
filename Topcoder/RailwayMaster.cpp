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

struct Edge {
    int u, v, w;
    bool operator < (const Edge &oth) const {
        return w < oth.w;
    }
};

class RailwayMaster {
public:
    int pa[105];
    int root(int x) {
        return pa[x] == x ? x : pa[x] = root(pa[x]);
    }
    int maxProfit(int n, int m, int k, vector<int> a, vector<int> b, vector<int> v) {
        vector<Edge> e;
        int ans = 0;
        rep(i,m) {
            e.push_back({a[i], b[i], v[i]});
        }
        rep(i,n) {
            pa[i] = i;
        }
        sort(e.begin(), e.end());
        vector<bool> f(m, 0);
        rep(i,m) {
            int x = root(e[i].u);
            int y = root(e[i].v);
            if (x == y) continue;
            f[i] = 1;
            pa[y] = x;
        }
        ford(i,m-1,0) {
            if (!k) break;
            if (f[i]) continue;
            --k;
            ans += e[i].w;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    RailwayMaster t;
    cout << t.maxProfit(3,3,3,{0, 1, 2},{1, 2, 0},{224, 258, 239});
    return 0;
}