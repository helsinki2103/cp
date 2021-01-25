#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int x; cin >> x;
        cout << (int64_t)(x) * (int64_t)(x + 2) * (int64_t)(2 * x + 1) / 8 << '\n';
    }
    return 0;
}