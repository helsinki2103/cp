#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int n, m; cin >> n >> m;
        int maxN = 0, maxM = 0;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            maxN = max(maxN, x);
        }
        for(int i=0; i<m; i++){
            int x; cin >> x;
            maxM = max(maxM, x);
        }
        cout << (maxN>=maxM?"Godzilla\n":"MechaGodzilla\n");
    }
    return 0;
}