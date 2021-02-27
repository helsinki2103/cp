#include<bits/stdc++.h>

using namespace std;

class ChristmasBatteries {
public:
    int calc(int i, int X, int Y, int Z, int M) {
        return (((X * i) % M * i) % M + Y * i + Z) % M;
    }
    int mostFun(int B, int N, int X, int Y, int Z, int M) {
        vector<vector<int> > dp(N + 1, vector<int> (B + 1, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= B; j++) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                if (j + i % 5 <= B) {
                    dp[i + 1][j + i % 5] = max(dp[i + 1][j + i % 5], dp[i][j] + calc(i, X, Y, Z, M));
                }
            }
        }
        return *max_element(dp[N].begin(), dp[N].end());
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ChristmasBatteries tst;
    cout << tst.mostFun(2, 12345, 234, 34, 5, 117);
    return 0;
}