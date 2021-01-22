#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n, m; cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        cin >> a[i][j];
        if (j>0) a[i][j] += a[i][j - 1];
    }
    int ans = 0;
    for(int i=0; i<m; i++) for(int j=i+1; j<m; j++) {
        int sum = 0;
        for(int k=0; k<n; k++){
            sum += a[k][j];
            if (i>0) sum -= a[k][i - 1];
            ans = max(ans, sum);
            if (sum<0) sum = 0;
        }
    }
    cout << ans;
    return 0;
}