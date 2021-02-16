#include<bits/stdc++.h>

using namespace std;

int calc(int st, int a, int b, int c) {
    int cnt = 0;
    for (int i = st; ; i++) {
        if (i % 7 == 0 || i % 7 == 3 || i % 7 == 6) {
            if (a) {
                cnt++;
                a--;
            } else break;
        } else if (i % 7 == 1 || i % 7 == 5) {
            if (b) {
                cnt++;
                b--;
            } else break;
        } else {
            if (c) {
                cnt++;
                c--;
            } else break;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, c; cin >> a >> b >> c;
    int w = min({a/3, b/2, c/2});
    a -= w * 3;
    b -= w * 2;
    c -= w * 2;
    int res = 0;
    for (int i = 0; i < 7; i++) res = max(res, calc(i, a, b, c));
    
    cout << w * 7 + res;
    return 0;
}