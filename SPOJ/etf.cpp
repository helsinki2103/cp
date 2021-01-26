#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int n; cin >> n;
        int res = n;
        for(int i=2; i*i<=n; i++){
            if (n%i==0){
                res -= res/i;
                while (n%i==0) n/=i;
            }
        }
        if (n>1) res -= res/n;
        cout << res << '\n';
    }
    return 0;
}