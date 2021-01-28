#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--){
        int n; cin >> n;
        vector<int64_t> b(2*n);
        vector<int64_t> a;
        map<int64_t, int> mp;
        for(int i=0; i<2*n; i++){
            cin >> b[i];
            mp[b[i]]++;
        }
        bool f = 1;
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        for(int i=0; i<2*n; i++){
            if (mp[b[i]]!=2){
                f = 0;
                break;
            }
        }
        if (!f){
            cout << "NO\n";
            continue;
        }
        for(int i=0; i<2*n; i+=2){
            a.push_back(b[i]);
        }
        int64_t curSub = 0;
        
        mp.clear();
        for(int i=0; i<n; i++){
            if ((a[i] - 2 * curSub) % (2ll * (n - i)) == 0 && (a[i] - 2 * curSub) > 0){
                mp[(a[i] - 2 * curSub) / (2ll * (n - i))]++;
                if (mp[(a[i] - 2 * curSub) / (2ll * (n - i))]>1){
                    f = 0;
                    break;
                }
                curSub += (a[i] - 2 * curSub) / (2ll * (n - i));
            }
            else{
                f = 0;
                break;
            }
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}