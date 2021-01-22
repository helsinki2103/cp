#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n), l(n), r(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        l[i] = i;
        while (l[i]>0 && abs(a[l[i] - 1] - a[i])<=k) l[i] = l[l[i] - 1];
    }
    for(int i=n-1; i>=0; i--){
        r[i] = i;
        while (r[i]<n-1 && abs(a[r[i] + 1] - a[i])<=k) r[i] = r[r[i] + 1];
    }
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    for(int i=0; i<n; ){
        v.push_back(r[i] - l[i] + 1);
        i = r[i] + 1;
    }
    for(int i=0; i<n; i++) cout << l[i] << " " << r[i] << '\n';
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    cout << v[0] + v[1];
    return 0;
}