#include<bits/stdc++.h>

using namespace std;
const int N = 15e2 + 5;
const int inf = 1e9;

int n, m;
char a[N][N];
int h[N][N];
int sx = -1, sy, tx, ty;
bool vis[N][N];

bool check(int x){
    queue<pair<int, int> > q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) vis[i][j] = 0;
    }
    q.push({sx, sy});
    vis[sx][sy] = 1;
    while (q.size()){
        int u = q.front().first;
        int v = q.front().second;
        if (u==tx && v==ty) return true;
        q.pop();
        if (u>1 && h[u - 1][v]<=x && !vis[u - 1][v]){
            vis[u - 1][v] = 1;
            q.push({u - 1, v});
        }
        if (u<n && h[u + 1][v]<=x && !vis[u + 1][v]){
            vis[u + 1][v] = 1;
            q.push({u + 1, v});
        }
        if (v>1 && h[u][v - 1]<=x && !vis[u][v - 1]){
            vis[u][v - 1] = 1;
            q.push({u, v - 1});
        }
        if (v<m && h[u][v + 1]<=x && !vis[u][v + 1]){
            vis[u][v + 1] = 1;
            q.push({u, v + 1});
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i] + 1;
    queue<pair<int, int> > q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            h[i][j] = inf;
            if (a[i][j]!='X') h[i][j] = 0;
            if (a[i][j]!='X'){
                if (a[i - 1][j]=='X' || a[i + 1][j]=='X' || a[i][j - 1]=='X' || a[i][j + 1]=='X'){
                    q.push({i, j});
                }
            }
            if (a[i][j]=='L'){
                if (sx==-1) sx = i, sy = j;
                else tx = i, ty = j;
            }
        }
    }
    while (q.size()){
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        if (u>1 && h[u - 1][v] > h[u][v] + 1){
            h[u - 1][v] = h[u][v] + 1;
            q.push({u - 1, v});
        }
        if (u<n && h[u + 1][v] > h[u][v] + 1){
            h[u + 1][v] = h[u][v] + 1;
            q.push({u + 1, v});
        }
        if (v>1 && h[u][v - 1] > h[u][v] + 1){
            h[u][v - 1] = h[u][v] + 1;
            q.push({u, v - 1});
        }
        if (v<m && h[u][v + 1] > h[u][v] + 1){
            h[u][v + 1] = h[u][v] + 1;
            q.push({u, v + 1});
        }
    }

    int l = 0, r = n*m/2;
    while (l<=r){
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << '\n';
    return 0;
}