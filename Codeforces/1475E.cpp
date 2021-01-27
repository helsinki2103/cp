#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;

int64_t memo[N][N];

int64_t C(int n, int k){
    if (k==0) return 1;
    if (k==n) return 1;
    if (memo[n][k]!=-1) return memo[n][k];
    return memo[n][k] = (C(n - 1, k - 1) % mod + C(n - 1, k) % mod)%mod;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    memset(memo,255,sizeof memo);
    while (nTest--){
        int64_t k, n; cin >> n >> k;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> v;
        v.push_back(1);
        for(int i=1; i<a.size(); i++){
            if (a[i]==a[i - 1]) v.back()++;
            else v.push_back(1);
        }
        reverse(v.begin(), v.end());
        v.push_back(0);
        int cur = 0, last = -1;
        for(int i=0; i<v.size(); i++){
            cur += v[i];
            if (cur>=k){
                last = i;
                break;
            }
        }
        if (cur<k) cout << -1 << '\n';
        else cout << C(v[last], cur - k) << '\n';
    }
    return 0;
}