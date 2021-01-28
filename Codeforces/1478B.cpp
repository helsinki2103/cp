#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--){
        int q, d; cin >> q >> d;
        for(int i=0; i<q; i++){
            int x; cin >> x;
            bool f = 0;
            for(int j=0; j<500; j++){
                if (x<0) break;
                int y = x;
                while (y){
                    int r = y%10;
                    if (r==d){
                        f = 1;
                        break;
                    }
                    y /= 10;
                }
                if (f) break;
                x -= d;
            }
            if (f) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}