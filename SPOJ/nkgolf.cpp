#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m, -1), h(m, 0), l(m), r(m);
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[j];
            if (a[j]>=b[j]) h[j]++;
            else h[j] = 1;
        }
        for(int j=0; j<m; j++){
            l[j] = j;
            while (l[j]>0 && h[l[j] - 1]>=h[j] && a[l[j] - 1]<=a[j] && b[l[j] - 1]<=b[j]) l[j] = l[l[j] - 1];
        }
        for(int j=m-1; j>=0; j--){
            r[j] = j;
            while (r[j]<m-1 && h[r[j] + 1]>=h[j] && a[r[j] + 1]>=a[j] && b[r[j] + 1]>=b[j]) r[j] = r[r[j] + 1];
        }
        for(int j=0; j<m; j++){
            res = max(res, h[j] * (r[j] - l[j] + 1));
            //res = max(res, h[j] * (j - l[j] + 1));
        }
        for(int j=0; j<m; j++) b[j] = a[j];
    }
    for(int j=0; j<m; j++) cout << h[j] << " ";
    cout << '\n';
    cout << res;
    return 0;
}