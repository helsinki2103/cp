#include<bits/stdc++.h>

using namespace std;

struct myData {
    int l, r, cnt, f;
    bool operator < (const myData &oth) const {
        if (f < oth.f) return true;
        if (f == oth.f && f == 1 && cnt > oth.cnt) return true;
        if (f == oth.f && f == 0 && cnt < oth.cnt) return true;
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        s = s + ' ';
        priority_queue<myData> pq;
        int cnt = 0;
        int ans = 0;
        vector<pair<int, int> > v;
        int l = -1, r = -1;
        for (int i = 0; i <= n; i++) {
            if (s[i] == 'L') {
                if (l == -1) l = i;
            } else {
                if (i > 0 && s[i - 1] == 'L') {
                    v.push_back({l, i - 1});
                    l = -1;
                }
            }
        }
        cnt = 0;
        for (int i = 0; i <= n; i++) {
            if (s[i] == 'W') cnt++;
            else if (cnt > 0) {
                ans += 2 * cnt - 1;
                cnt = 0;
            }
        }
        for (auto [x, y]: v) {
            int score = 0;
            int f = 0;
            if (x > 0 && s[x - 1] == 'W' && y < n - 1 && s[y + 1] == 'W') 
            {
                score = 2 * (y - x + 1) + 1;
                f = 1;
            } else if (x > 0 && s[x - 1] == 'W') score = 2 * (y - x + 1);
            else if (y < n - 1 && s[y + 1] == 'W') score = 2 * (y - x + 1);
            else score = 2 * (y - x + 1) - 1;
            pq.push({x, y, score, f});
            // cout << x << " " << y << " " << score << '\n';
        }
        while (k) {
            if (pq.empty()) break;
            int l = pq.top().l;
            int r = pq.top().r;
            int score = pq.top().cnt;
            // if (nTest == 7) cout << l << " " << r << " " << score << " ";
            pq.pop();
            if (k >= r - l + 1) {
                ans += score;
                k -= (r - l + 1);
            } else {
                if (l > 0 && s[l - 1] == 'W') ans += k * 2;
                else if (r < n - 1 && s[r + 1] == 'W') ans += k * 2;
                else ans += k * 2 - 1;
                break;
            }
        }
        // for (auto [x, y]: v) cout << x << " " << y << '\n';
        cout << ans << '\n';
    }
    return 0;
}