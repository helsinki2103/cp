#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int n; cin >> n;
        int64_t sum = 0;
        for(int i=0; i<n; i++){
            int64_t x; cin >> x;
            sum += x;
            sum %= n;
        }
        cout << (sum==0?"YES\n":"NO\n");
    }
    return 0;
}