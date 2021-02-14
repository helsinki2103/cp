#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            cout << (1 << __lg(x)) << " ";
        }
        cout << '\n';
    }
    return 0;
}