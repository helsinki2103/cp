#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int x; cin >> x;
        bool f = 0;
        for(int i=0; i<500; i++){
            if (f) break;
            int l = 0, r = 500;
            while (l<=r){
                int mid = (l + r) >> 1;
                int cur = i * 2020 + mid * 2021;
                if (cur>x) r = mid - 1;
                else if (cur<x) l = mid + 1;
                else if (cur==x){
                    f = 1;
                    break;
                }
            }
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}