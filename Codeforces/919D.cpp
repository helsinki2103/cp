#include<bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;

vector<int> adj[N];
int inDeg[N], dp[N][26];


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    s = ' ' + s;
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        inDeg[v]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if (!inDeg[i]) q.push(i);
    }
    int cnt = 0;
    memset(dp,0,sizeof dp);
    while (q.size()){
        int u = q.front();
        q.pop();
        dp[u][s[u] - 'a']++;
        ++cnt;
        for(int v: adj[u]){
            for(int i=0; i<26; i++) dp[v][i] = max(dp[v][i], dp[u][i]);
            inDeg[v]--;
            if (!inDeg[v]) q.push(v);
        }
    }
    if (cnt!=n) cout << -1;
    else{
        int res = 0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<26; j++) res = max(res, dp[i][j]);
        }
        cout << res;
    }
    return 0;
}