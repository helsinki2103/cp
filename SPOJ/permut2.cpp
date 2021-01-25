#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n;
    while(cin >> n && n){
        vector<int> a(n + 1), b(n + 1);
        for(int i=1; i<=n; i++){
            cin >> a[i];
            b[a[i]] = i;
        }
        bool f = 1;
        for(int i=1; i<=n; i++){
            f &= (a[i]==b[i]);
        }
        if (f) cout << "ambiguous\n";
        else cout << "not ambiguous\n";
    }
    return 0;
}