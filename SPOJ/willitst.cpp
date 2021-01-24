#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    int64_t base = 1;
    for(int i=0; ; i++){
        if (n==base){
            cout << "TAK\n";
            break;
        }
        if (base>n){
            cout << "NIE\n";
            break;
        }
        base *= 2ll;
    }
    return 0;   
}