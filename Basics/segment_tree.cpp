/*
Task: 
Date: 
Author: aLittleLove (Minh Vu)
*/

#include<bits/stdc++.h>
#define rep(i,n) for (int i=0, _n=n; i<_n; i++)
#define FOR(i,a,b) for (int _a=(a), _b=(b), i=_a; _a<=_b?i<=_b:i>=_b; _a<=_b?i++:i--)
#define _mem(a, b) memset(a, (b), sizeof(a))
#define pb push_back
#define fi first
#define se second
#define sz(a) int((a).size())

using namespace std;
typedef long long ll;
typedef int64_t i64;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
const int N = 2e5 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const double pi = atan(1) * 4.0;
template<typename T, typename U> inline void mini(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void maxi(T &x, U y) { if(x < y) x = y; }

int st[N<<2];
int a[N];

void build(int k, int l, int r)
{
    if (l==r)
    {
        st[k] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    st[k] = max(st[k<<1], st[k<<1|1]);
}

int get(int k, int l, int r, int u, int v)
{
    if (l>=u && r<=v) return st[k];
    if (l>v || r<u) return -inf;
    int mid = (l + r) >> 1;
    return max(get(k<<1,l,mid,u,v), get(k<<1|1,mid+1,r,u,v));
}

void Solve()
{
    int n; cin >> n;
    FOR(i,1,n) cin >> a[i];
    build(1,1,n);
    int q; cin >> q;
    while (q--)
    {
        int u, v; cin >> u >> v;
        cout << get(1,1,n,u,v) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();

    return 0;
}