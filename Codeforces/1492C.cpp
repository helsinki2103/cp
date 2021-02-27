#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; nTest = 1;
    while (nTest--) {
        int n, m; cin >> n >> m;
        string s, t; cin >> s >> t;
        vector<int> left(m), right(m);
        int j = 0;
        for (int i = 0; i < m; i++) {
            while (s[j] != t[i]) j++;
            left[i] = j;
            j++;
        }
        j = n - 1;
        for (int i = m - 1; i >= 0; i--) {
            while (s[j] != t[i]) j--;
            right[i] = j;
            j--;
        }
        // for (int i = 0; i < m; i++) cout << left[i] << " ";
        int ans = 0;
        for (int i = 1; i < m; i++) ans = max(ans, right[i] - left[i - 1]);
        cout << ans << '\n';
    }
    return 0;
}