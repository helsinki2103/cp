#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

int pa[N], sz[N];

int findset(int x)
{
    return pa[x]==-1 ? x : pa[x] = findset(pa[x]);
}

void Solve()
{
    map<string, int> mp;
    int n; cin >> n;
    int cnt = 0;
    for (int i=1; i<N; i++) sz[i] = 1;
    memset(pa,255,sizeof pa);
    for (int i=1; i<=n; i++)
    {
        string a, b; cin >> a >> b;
        if (mp[a]==0) mp[a] = ++cnt;
        if (mp[b]==0) mp[b] = ++cnt;
        int x = findset(mp[a]), y = findset(mp[b]);
        if (x!=y)
        {
            if (sz[x]<sz[y]) swap(x, y);
            sz[x] += sz[y];
            pa[y] = x;
        }
        cout << sz[x] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();
}