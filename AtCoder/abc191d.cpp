#include<bits/stdc++.h>
#define ld long double

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ld x0, y0, r; cin >> x0 >> y0 >> r;
    int64_t ans = 0;
    r += 1e-14;
    int64_t ly = ceil(y0 - r);
    int64_t ry = floor(y0 + r);
    for (int64_t y = ly; y <= ry; y++) {
        int64_t lx = ceil(x0 - sqrt(r * r - (y - y0) * (y - y0)));
        int64_t rx = floor(x0 + sqrt(r * r - (y - y0) * (y - y0)));
        ans += (rx - lx + 1);
    }
    cout << ans;
    return 0;
}