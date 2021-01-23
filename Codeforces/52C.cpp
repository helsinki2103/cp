#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N = 2e5 + 5;
const int inf = 1e9;

struct SegTree
{
    int val, lazy;
};

int n, m;
int a[N];
SegTree st[N<<2];

void down(int k)
{
    st[k<<1].val += st[k].lazy;
    st[k<<1].lazy += st[k].lazy;

    st[k<<1|1].val += st[k].lazy;
    st[k<<1|1].lazy += st[k].lazy;

    st[k].lazy = 0;
}

void build(int k, int l, int r)
{
    if (l>r) return;
    if (l==r)
    {
        st[k].val = a[l];
        st[k].lazy = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    st[k].val = min(st[k<<1].val, st[k<<1|1].val);
}

void update(int k, int l, int r, int u, int v, int val)
{
    if (l>v || r<u) return;
    if (l>=u && r<=v)
    {
        st[k].val += val;
        st[k].lazy += val;
        return;
    }
    down(k);
    int mid = (l + r) >> 1;
    update(k<<1,l,mid,u,v,val);
    update(k<<1|1,mid+1,r,u,v,val);
    st[k].val = min(st[k<<1].val,st[k<<1|1].val);
}

int get(int k, int l, int r, int u, int v)
{
    if (l>v || r<u) return inf;
    if (l>=u && r<=v) return st[k].val;
    down(k);
    int mid = (l + r) >> 1;
    return min(get(k<<1,l,mid,u,v),get(k<<1|1,mid+1,r,u,v));
}

int32_t main()
{
    freopen("input.txt","r",stdin);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    build(1,1,n);
    cin >> m;
    string s;
    getline(cin, s);
    for (int i=1; i<=m; i++)
    {
        getline(cin, s);
        int l = -inf, r = -inf, v = -inf, num = 0;
        s = s + ' ';
        bool sign = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='-')
            {
                sign = 1;
            }
            else if (s[i]>='0' && s[i]<='9')
            {
                num *= 10;
                num += (int)(s[i] - '0');
            }
            else 
            {
                if (sign) num = -num;
                if (l==-inf) l = num;
                else if (r==-inf) r = num;
                else v = num;
                num = 0;
                sign = 0;
            }
        }
        //cout << l << " " << r << '\n';
        ++l; ++r;
        if (v!=-inf)
        {
            if (l>r)
            {
                update(1,1,n,l,n,v);
                update(1,1,n,1,r,v);
            }
            else update(1,1,n,l,r,v);
        }
        else 
        {
            if (l>r)
            {
                cout << min(get(1,1,n,l,n), get(1,1,n,1,r)) << '\n';
            }
            else cout << get(1,1,n,l,r) << '\n';
        }
    }
}