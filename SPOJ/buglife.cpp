#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;

vector<vector<int> > adj;
bool f = 1;
int h[N];
bool vis[N];

void dfs(int u, int pa = -1){
    if (!f) return;
    for(int v: adj[u]){
        if (v==pa) continue;
        if (vis[v]){
            if (h[v]==h[u]){
                f = 0;
                return;
            }
        }
        else{
            h[v] = 1 - h[u];
            vis[v] = 1;
            dfs(v, u);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; scanf("%d",&nTest);
    for(int iTest=1; iTest<=nTest; iTest++){
        printf("Scenario #%d:\n",iTest);
        int n, m; scanf("%d %d",&n,&m);
        adj.resize(n);
        for(int i=0; i<n; i++) adj[i].clear();
        for(int i=0; i<m; i++){
            int u, v; scanf("%d %d",&u,&v);
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        f = 1;
        memset(vis,0,sizeof vis);
        memset(h,0,sizeof h);
        for(int i=0; i<n; i++) if (!vis[i]) dfs(i);
        if (f) printf("No suspicious bugs found!\n");
        else printf("Suspicious bugs found!\n");
    }
    return 0;
}