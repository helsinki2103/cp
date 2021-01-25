#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int l;
    while (cin >> l && l){
        cout << fixed << setprecision(2) << (double)(l * l) / (8.0 * atan(1.0)) << '\n';
    }
    return 0;
}