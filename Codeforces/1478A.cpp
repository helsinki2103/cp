#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int n; cin >> n;
        vector<int> cnt(n);
        for(int i=0; i<n; i++){
            int x; cin >> x;
            cnt[--x]++;
        }
        int res = 0;
        for(int i=0; i<n; i++) res = max(res, cnt[i]);
        cout << res << '\n';
    }
    return 0;
}