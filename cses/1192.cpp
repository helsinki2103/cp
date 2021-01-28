#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    string s[n];
    for(int i=0; i<n; i++) cin >> s[i];
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (s[i][j]=='.'){
                ans++;
                queue<pair<int, int> > q;
                q.push({i, j});
                s[i][j] = '#';
                while (q.size()){
                    int u = q.front().first;
                    int v = q.front().second;
                    q.pop();
                    if (u>0 && s[u - 1][v]=='.'){
                        s[u - 1][v] = '#';
                        q.push({u - 1, v});
                    }
                    if (u<n-1 && s[u + 1][v]=='.'){
                        s[u + 1][v] = '#';
                        q.push({u + 1, v});
                    }
                    if (v>0 && s[u][v - 1]=='.'){
                        s[u][v - 1] = '#';
                        q.push({u, v - 1});
                    }
                    if (v<m-1 && s[u][v + 1]=='.'){
                        s[u][v + 1] = '#';
                        q.push({u, v + 1});
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}