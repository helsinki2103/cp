#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

vector<int> a[N];
int n;
int trace[N];
bool vis[N];

void Solve()
{
    cin >> n;
    for (int i=1; i<n; i++)
    {
        int k; cin >> k;
        a[i].clear();
        for (int j=1; j<=k; j++)
        {
            int x; cin >> x;
            a[i].push_back(x);
        }
    }
    for (int i=1; i<=n; i++) sort(a[i].begin(), a[i].end());
    queue<int> q;
    q.push(1);
    memset(trace,-1,sizeof trace);
    bool f = 0;
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v: a[u])
        {
            if (trace[v]==-1)
            {
                trace[v] = u;
                q.push(v);
                if (v==n) 
                {
                    f = 1;
                    break;
                }
            }
        }
        if (f) break;
    }

    if (!f) cout << "-1\n\n";
    else 
    { 
        vector<int> path;
        int v = n;
        while (v!=1)
        {
            path.push_back(trace[v]);
            v = trace[v];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for (int x: path) cout << x << " ";
        cout << '\n';
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) Solve();
}