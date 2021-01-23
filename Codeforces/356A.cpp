/*
Task: 356A
Date: Dec 23, 2020
Author: aLittleLove (Minh Vu)
*/

#include<bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;

int n, m;
int st[N<<2];

void down(int k)
{
    if (st[k<<1]==0) st[k<<1] = st[k];
    if (st[k<<1|1]==0) st[k<<1|1] = st[k];
    st[k] = 0;
}

void update(int k, int l, int r, int u, int v, int x)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v)
    {
        if (st[k]==0) st[k] = x;
        return;
    }
    down(k);
    int mid = (l + r) >> 1;
    update(k<<1,l,mid,u,v,x);
    update(k<<1|1,mid+1,r,u,v,x);
}

void show(int k, int l, int r)
{
    if (l==r)
    {
        cout << st[k] << " ";
        return;
    }
    down(k);
    int mid = (l + r) >> 1;
    show(k<<1,l,mid);
    show(k<<1|1,mid+1,r);
}

void Solve()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++)
    {
        int u, v, x; cin >> u >> v >> x;
        update(1,1,n,u,x-1,x);
        update(1,1,n,x+1,v,x);
    }
    show(1,1,n);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest;
    nTest = 1;
    while (nTest--) Solve();

    return 0;
}