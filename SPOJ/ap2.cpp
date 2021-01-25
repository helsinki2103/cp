#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int64_t x, y, z; cin >> x >> y >> z;
        int64_t n = (2 * z) / (x + y);
        int64_t d = (y - x) / (n - 5);
        x -= 2 * d;
        cout << n << '\n';
        for(int i=0; i<n; i++){
            cout << x << " ";
            x += d;
        }
        cout << '\n';
    }
    return 0;
}