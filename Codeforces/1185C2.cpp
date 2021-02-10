#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> t(n), cnt(101, 0);
    for (int i = 0; i < n; i++) cin >> t[i];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int d = sum + t[i] - m;
        int k = 0;
        if (d > 0) {
            for (int j = 100; j > 0; j--) {
                int x = j * cnt[j];
                if (d <= x) {
                    k += (d + j - 1) / j;
                    break;
                }
                d -= x;
                k += cnt[j];
            }
        }
        sum += t[i];
        cnt[t[i]]++;
        cout << k << " ";
    }
    return 0;
}