#include<bits/stdc++.h>

using namespace std;
double dp[101][101][101];

double calc(int a, int b, int c) {
    if (a == 100 || b == 100 || c == 100) return 0;
    if (dp[a][b][c]) return dp[a][b][c];
    double ans = 0;
    ans += (calc(a + 1, b, c) + 1) * a / (a + b + c);
    ans += (calc(a, b + 1, c) + 1) * b / (a + b + c);
    ans += (calc(a, b, c + 1) + 1) * c / (a + b + c);
    dp[a][b][c] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, c; cin >> a >> b >> c;
    memset(dp,0,sizeof dp);
    cout << fixed << setprecision(6) << calc(a, b, c) << '\n';
    return 0;
}