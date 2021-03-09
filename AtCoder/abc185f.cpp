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
const int N = 3e5 + 5;

ll a[N];
ll tree[N<<2];

void build(int k, int l, int r) {
    if (l > r) return;
    if (l == r) {
        tree[k] = a[l];
        // cout << k << " " << l << " " << tree[k] << "\n";
        return;
    }
    int mid = (l + r) >> 1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tree[k] = tree[k<<1] ^ tree[k<<1|1];
    // cout << k << " " << tree[k] << '\n';
}

ll query(int k, int l, int r, int u, int v) {
    if (r < u || l > v) return 0;
    if (l >= u && r <= v) return tree[k];
    int mid = (l + r) >> 1;
    return query(k<<1,l,mid,u,v) ^ query(k<<1|1,mid+1,r,u,v);
}

void upd(int k, int l, int r, int u, ll v) {
    if (r < u || l > u) return;
    if (l == u && r == u) {
        a[l] ^= v;
        tree[k] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    upd(k<<1,l,mid,u,v);
    upd(k<<1|1,mid+1,r,u,v);
    tree[k] = tree[k<<1] ^ tree[k<<1|1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n, q; cin >> n >> q;
    fore(i,1,n) cin >> a[i];
    build(1,1,n);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int u; cin >> u;
            ll v; cin >> v;
            upd(1,1,n,u,v);
        } else {
            int u; cin >> u;
            int v; cin >> v;
            cout << query(1,1,n,u,v) << '\n';
        }
    }
    return 0;
}