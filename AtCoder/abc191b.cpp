#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        if (k != x) a.push_back(k);
    }
    for (int k: a) cout << k << " ";
    return 0;
}