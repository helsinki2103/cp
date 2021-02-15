#include<bits/stdc++.h>

using namespace std;
const int inf = 1e9;

const int N = (1 << 17) + 5;

int pref[N][26];

int calc(int l, int r, int c) {
    if (l > r) return 0;
    if (l == r) return 1 - (pref[r][c] - pref[r - 1][c]);
    if (r - l + 1 == 2) {
        int fi = 2 - (pref[r][c] - pref[r - 1][c]) - (pref[l][c + 1] - pref[l - 1][c + 1]);
        int se = 2 - (pref[r][c + 1] - pref[r - 1][c + 1]) - (pref[l][c] - pref[l - 1][c]);
        return min(fi, se);
    }
    int mid = (l + r - 1) >> 1;
    return min(calc(l, mid, c + 1) + r - mid - (pref[r][c] - pref[mid][c]), calc(mid + 1, r, c + 1) + mid - l + 1 - (pref[mid][c] - pref[l - 1][c]));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        string s; cin >> s;
        s = ' ' + s;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 26; j++) pref[i][j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            pref[i][s[i] - 'a']++;
            for (int j = 0; j < 26; j++) pref[i][j] += pref[i - 1][j];
        }
        cout << calc(1,n,0) << '\n';
    }
    return 0;
}