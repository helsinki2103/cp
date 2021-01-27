#include<bits/stdc++.h>

using namespace std;
const int inf = 1e9;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int n, m; cin >> n >> m;
        vector<int64_t> a[2];
        vector<int> b(n);
        for(int i=0; i<n; i++) cin >> b[i];
        for(int i=0; i<n; i++){
            int x; cin >> x;
            --x;
            a[x].push_back(b[i]);
        }
        for(int i=0; i<2; i++){
            sort(a[i].begin(), a[i].end());
            a[i].push_back(0);
            reverse(a[i].begin(), a[i].end());
            for(int j=1; j<a[i].size(); j++) a[i][j] += a[i][j - 1];
        }
        int res = inf;
        for(int i=0; i<a[0].size(); i++){
            int j = lower_bound(a[1].begin(), a[1].end(), m - a[0][i]) - a[1].begin();
            if (j>=0 && j<a[1].size() && a[0][i] + a[1][j] >= m){
                res = min(res, i + 2 * j);
            }
        }
        if (res==inf) res = -1;
        cout << res << '\n';
    }
    return 0;
}