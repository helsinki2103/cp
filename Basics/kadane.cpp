#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int sum = 0, ans = 0;
    for(int i=0; i<n; i++){
        sum += a[i];
        ans = max(ans, sum);
        if (sum<0) sum = 0;
    }
    return 0;
}