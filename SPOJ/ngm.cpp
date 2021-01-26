#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if (n%10==0) cout << "2\n";
    else cout << 1 << '\n' << n%10 << '\n';
    return 0;
}