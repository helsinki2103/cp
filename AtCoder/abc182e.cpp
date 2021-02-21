#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int h, w, n, m; cin >> h >> w >> n >> m;
    vector<vector<int> > a(h, vector<int>(w));
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[x - 1][y - 1] = 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        a[x - 1][y - 1] = -1;
    }
    for (int i = 0; i < h; i++) {
        bool light = false;
        for (int j = 0; j < w; j++) {
            if (a[i][j] == 1) {
                light = true;
            } else if (a[i][j] == -1) {
                light = false;
            } else if (light) {
                a[i][j] = 2;
            }
        }
        light = false;
        for (int j = w - 1; j >= 0; j--) {
            if (a[i][j] == 1) {
                light = true;
            } else if (a[i][j] == -1) {
                light = false;
            } else if (light) {
                a[i][j] = 2;
            }
        }
    }

    for (int j = 0; j < w; j++) {
        bool light = false;
        for (int i = 0; i < h; i++) {
            if (a[i][j] == 1) {
                light = true;
            } else if (a[i][j] == -1) {
                light = false;
            } else if (light) {
                a[i][j] = 2;
            }
        }
        light = false;
        for (int i = h - 1; i >= 0; i--) {
            if (a[i][j] == 1) {
                light = true;
            } else if (a[i][j] == -1) {
                light = false;
            } else if (light) {
                a[i][j] = 2;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans += (a[i][j] > 0);
        }
    }
    cout << ans;
    return 0;
}