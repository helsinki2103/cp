#include<bits/stdc++.h>

using namespace std;

class IslandInALake {
public:
    vector<vector<int> > f;
    vector<vector<int> > a;
    int n, m;
    void bfs(int x, int y, int c) {
        const int dx[4] = {-1, 0, 1, 0};
        const int dy[4] = {0, -1, 0, 1};
        queue<pair<int, int> > q;
        q.push({x, y});
        f[x][y] = c;
        while (q.size()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newu = u + dx[i];
                int newv = v + dy[i];
                if (newu < 0 || newu >= n || newv < 0 || newv >= m) continue;
                if (a[newu][newv] == 1 && !f[newu][newv]) {
                    f[newu][newv] = c;
                    q.push({newu, newv});
                }
            }
        }
    }
    void bfs2(int x, int y, int c) {
        const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        queue<pair<int, int> > q;
        q.push({x, y});
        f[x][y] = c;
        while(q.size()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int newu = u + dx[i];
                int newv = v + dy[i];
                if (newu < 0 || newu >= n || newv < 0 || newv >= m) continue;
                if (a[newu][newv] == 2 && !f[newu][newv]) {
                    f[newu][newv] = c;
                    q.push({newu, newv});
                }
                if (a[newu][newv] == 1 && !f[newu][newv]) {
                    f[newu][newv] = c;
                }
            }
        }
    }
    int bfs3(int x, int y) {
        const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        queue<pair<int, int> > q;
        q.push({x, y});
        f[x][y] = 3;
        int cnt = 0;
        while (q.size()) {
            int u = q.front().first;
            int v = q.front().second;
            ++cnt;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int newu = u + dx[i];
                int newv = v + dy[i];
                if (newu < 0 || newu >= n || newv < 0 || newv >= m) continue;
                if (!f[newu][newv]) {
                    f[newu][newv] = 3;
                    q.push({newu, newv});
                }
            }
        }
        return cnt;
    }
    int build(vector<string> country) {
        n = country.size();
        m = country[0].size();
        f.resize(n, vector<int>(m, 0));
        a.resize(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (country[i][j] == '.') a[i][j] = 1;
                else a[i][j] = 2;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1 && !f[i][j]) {
                    if (i == 0 || i == n - 1 || j == 0 || j == m - 1) bfs(i, j, 1);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 2 && !f[i][j]) bfs2(i, j, 2);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (f[i][j] == 0) ans = max(ans, bfs3(i, j));
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) cout << f[i][j] << " ";
        //     cout << '\n';
        // }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    IslandInALake t;
    vector<string> v = {
        "...........",
        ".#########.",
        ".#.......#.",
        ".#.......#.",
        ".#.......#.",
        ".#.......#.",
        ".#.......#.",
        ".#.......#.",
        ".#...#...#.",
        ".#.......#.",
        ".#.......#.",
        ".#.......#.",
        ".#########.",
        "..........."};

    cout << t.build(v);
    return 0;
}