#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, s, d; cin >> n >> s >> d;
    bool f = 0;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        f |= (x < s && y > d);
    }
    cout << (f ? "Yes" : "No");
    return 0;
}