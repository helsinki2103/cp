#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int f[N], p[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int ans = 0;
    string s; cin >> s;
    int cnt = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'b') cnt++;
        else {
            ans += cnt;
            ans %= mod;
            cnt *= 2;
            cnt %= mod;
        }
    }
    cout << ans;
    return 0;
}