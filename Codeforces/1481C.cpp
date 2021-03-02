#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(n), c(m);
        for (int i = 0; i < n; i++) cin >> a[i], --a[i];
        for (int i = 0; i < n; i++) cin >> b[i], --b[i];
        for (int i = 0; i < m; i++) cin >> c[i], --c[i];
        vector<set<int> > pos(n);
        for (int i = 0; i < m; i++) {
            pos[c[i]].insert(i);
        }
        bool f = 1;
        vector<int> h(n, -1), ans(m, -1);
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            if (pos[b[i]].empty()) {
                f = 0;
                break;
            }
            h[i] = *(--pos[b[i]].end());
            ans[*(--pos[b[i]].end())] = i;
            pos[b[i]].erase(--pos[b[i]].end());
        }
        if (!f) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (h[i] != -1) continue;
            if (pos[b[i]].size()) {
                h[i] = *(--pos[b[i]].end());
                ans[*(--pos[b[i]].end())] = i;
                pos[b[i]].erase(--pos[b[i]].end());
            }
        }
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            for (auto it = pos[i].begin(); it != pos[i].end(); it++) {
                tmp.push_back(*it);
            }
        }
        sort(tmp.begin(), tmp.end(), greater<int>());
        for (int i = 0; i < n; i++) {
            while (tmp.size() && h[i] > tmp.back()) {
                ans[tmp.back()] = i;
                tmp.pop_back();
            }
        }
        f &= tmp.empty();
        if (!f) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < m; i++) cout << ans[i] + 1 << " ";
        cout << '\n';
    }
    return 0;
}