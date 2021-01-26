#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int64_t x; cin >> x;
        while (x%2==0) x/= 2;
        if (x==1) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}