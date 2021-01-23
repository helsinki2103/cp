#include<bits/stdc++.h>

using namespace std;

int main(){
    int nTest; cin >> nTest;
    while (nTest--){
        int64_t a, b; cin >> a >> b;
        if (!b){
            cout << 1 << '\n';
            continue;
        }
        vector<int> cnt(10, 0);
        a %= 10;
        vector<int> v; 
        v.push_back(a);
        cnt[a]++;
        for(int i=2; ; i++){
            v.push_back((v.back() * a)%10);
            if (++cnt[v.back()]==2){
                v.pop_back();
                b %= v.size();
                break;
            }
        }
        b--; if (b<0) b += v.size();
        cout << v[b] << '\n';
    }
    return 0;
}