#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--){
        int n, m, k; cin >> n >> m >> k;
        vector<pair<int, int> > edge;
        vector<int> a(k), b(k);
        vector<int> degA(n, 0), degB(m, 0);
        for(int i=0; i<k; i++){
            cin >> a[i];
            --a[i];
            degA[a[i]]++;
        }
        for(int i=0; i<k; i++){
            cin >> b[i];
            --b[i];
            degB[b[i]]++;
        }
        int64_t res = 0;
        for(int i=0; i<k; i++){
            res += k - 1 - (degA[a[i]] - 1) - (degB[b[i]] - 1);
        }
        res /= 2;
        cout << res << '\n';
    }
    return 0;
}