#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int64_t k, d; cin >> d >> k;
        int64_t x = (d - 1) / k + 1;
        x *= k;
        int64_t y = x;
        bool f = 0;
        while (x * x + y * y > d * d) {
            if (f) x -= k;
            else y -= k;
            f ^= 1;
        }
        if (((x + y) / k) % 2 == 1) cout << "Ashish\n";
        else cout << "Utkarsh\n";
        // cout << x << " " << y << '\n';
    }
    return 0;
}