#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int64_t> a(n), v;
    int64_t res = 0;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=n-1; i>=0; i--){
        res += a[i];
        if (i!=0) v.push_back(res);
    }
    sort(v.begin(), v.end());
    --k;
    while (k--){
        res += v.back();
        v.pop_back();
    }
    cout << res;
    return 0;
}