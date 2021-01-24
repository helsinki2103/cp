#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int64_t x; cin >> x;
        cout << 192 + (x - 1) * 250 << '\n';
    }
    return 0;
}