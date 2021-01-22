#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n, m; cin >> n >> m;
    vector<int> h(m, 0), l(m), r(m);
    int res = 0;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++){
            if (s[j]=='1') h[j]++;
            else h[j] = 0;
        }
        for(int j=0; j<m; j++){
            l[j] = j;
            while (l[j]>0 && h[l[j] - 1]>=h[j]) l[j] = l[l[j] - 1];
        }
        for(int j=m-1; j>=0; j--){
            r[j] = j;
            while (r[j]<m-1 && h[r[j] + 1]>=h[j]) r[j] = r[r[j] + 1];
        }
        for(int j=0; j<m; ){
            res += (h[j]>0) * (r[j] - l[j] + 1) * (r[j] - l[j] + 2) / 2;
            if(i) res += (h[j]>0) * (r[j] - l[j] + 1) * (r[j] - l[j] + 2) / 2;
            j = r[j];
        }
        cout << res << '\n';
    }
    cout << res;
    return 0;
}