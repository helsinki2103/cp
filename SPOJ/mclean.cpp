#include<bits/stdc++.h>

using namespace std;
const int N = 25;
const int inf = 1e7;

struct myData{
    int x, y, w;
};

char a[N][N];
int res;
int n, m;
bool vis[N][N];
int dist[N][N];

int bfs(int x, int y, int z, int t){
    queue<myData> q;
    q.push({x, y, 0});
    memset(vis,0,sizeof vis);
    vis[x][y] = 1;
    while (q.size()){
        int u = q.front().x;
        int v = q.front().y;
        int w = q.front().w;
        q.pop();
        if (u>1 && a[u - 1][v]!='x' && !vis[u - 1][v]){
            vis[u - 1][v] = 1;
            q.push({u - 1, v, w + 1});
            if (u - 1==z && v==t) return w + 1;
        }
        if (u<n && a[u + 1][v]!='x' && !vis[u + 1][v]){
            vis[u + 1][v] = 1;
            q.push({u + 1, v, w + 1});
            if (u + 1==z && v==t) return w + 1;
        }
        if (v>1 && a[u][v - 1]!='x' && !vis[u][v - 1]){
            vis[u][v - 1] = 1;
            q.push({u, v - 1, w + 1});
            if (u==z && v - 1==t) return w + 1;
        }
        if (v<m && a[u][v + 1]!='x' && !vis[u][v + 1]){
            vis[u][v + 1] = 1;
            q.push({u, v + 1, w + 1});
            if (u==z && v + 1==t) return w + 1;
        }
    }
    return inf;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    while (cin >> m >> n && n!=0 && m!=0){
        for(int i=1; i<=n; i++){
            cin >> a[i] + 1;
        }
        vector<pair<int, int> > des;
        int sx, sy;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (a[i][j]=='*'){
                    des.push_back({i, j});
                }
                if (a[i][j]=='o'){
                    sx = i;
                    sy = j;
                }
            }
        }
        memset(dist,0,sizeof dist);
        for(int i=0; i<des.size(); i++){
            dist[0][i + 1] = bfs(sx, sy, des[i].first, des[i].second);
            for(int j=0; j<des.size(); j++){
                if (i==j) continue;
                dist[i + 1][j + 1] = bfs(des[i].first, des[i].second, des[j].first, des[j].second);
            }
        }
        res = inf;
        vector<int> num;
        for(int i=0; i<des.size(); i++) num.push_back(i + 1);
        do{
            int sum = dist[0][num[0]];
            for(int i=1; i<num.size(); i++) sum += dist[num[i - 1]][num[i]];
            res = min(res, sum);
        } while (next_permutation(num.begin(), num.end()));
        if (res>=inf) res = -1;
        cout << res << '\n';
    }
    return 0;
}