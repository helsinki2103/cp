#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int n, m; cin >> n >> m;
        string s[n];
        for(int i=0; i<n; i++) cin >> s[i];
        vector<vector<bool> > vis(n, vector<bool>(m, 0));
        vector<int64_t> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (s[i][j]=='#' && !vis[i][j]){
                    queue<pair<int, int> > q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    int64_t cnt = 0;
                    while (q.size()){
                        int u = q.front().first;
                        int v = q.front().second;
                        cnt++;
                        q.pop();
                        if (u>0 && s[u - 1][v]=='#' && !vis[u - 1][v]){
                            q.push({u - 1, v});
                            vis[u - 1][v] = 1;
                        }
                        if (u<n-1 && s[u + 1][v]=='#' && !vis[u + 1][v]){
                            q.push({u + 1, v});
                            vis[u + 1][v] = 1;
                        }
                        if (v>0 && s[u][v - 1]=='#' && !vis[u][v - 1]){
                            q.push({u, v - 1});
                            vis[u][v - 1] = 1;
                        }
                        if (v<m-1 && s[u][v + 1]=='#' && !vis[u][v + 1]){
                            q.push({u, v + 1});
                            vis[u][v + 1] = 1;
                        }
                    }
                    ans.push_back(cnt);
                }
            }
        }
        int64_t t1 = 0, t2 = n * m;
        for(int i=0; i<ans.size(); i++){
            t1 += ans[i] * ans[i];
        }
        if (t1==0){
            cout << 0 << '\n';
            continue;
        }
        int64_t g = __gcd(t1, t2);
        t1 /= g; t2 /= g;
        if (t1%t2==0) cout << t1/t2 << '\n';
        else cout << t1 << " / " << t2 << '\n';
    }
    return 0;
}