#include<bits/stdc++.h>

using namespace std;
const int N = 10;

int a[N][N];
int n, k;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    vector<int> v;
    for (int i = 2; i <= n; i++) v.push_back(i);
    int ans = 0;
    do {
        int dist = a[1][v[0]] + a[v[v.size() - 1]][1];
        for (int i = 1; i < v.size(); i++) dist += a[v[i]][v[i - 1]];
        ans += (dist == k);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans;
    return 0;
}