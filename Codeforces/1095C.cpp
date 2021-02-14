#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(k, 0);
    int sum = k;
    for (int i = 0; i < k; i++) {
        while (sum + (1 << (a[i] + 1)) - (1 << a[i]) <= n) {
            sum += (1 << (a[i] + 1)) - (1 << a[i]);
            a[i]++;
        }
    }
    if (sum == n) {
        cout << "YES\n";
        for (int x: a) cout << (1 << x) << " ";
        cout << '\n';
    }
    else cout << "NO\n";
    return 0;
}