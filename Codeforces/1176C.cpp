#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<int, int> mp;
    mp[4] = 0;
    mp[8] = 1;
    mp[15] = 2;
    mp[16] = 3;
    mp[23] = 4;
    mp[42] = 5;
    vector<int> cnt(6, 0);
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        if (x==4) {
            cnt[mp[x]]++;
        }
        else {
            if (cnt[mp[x] - 1]) {
                cnt[mp[x]]++;
                cnt[mp[x] - 1]--;
            }
        }
    }
    cout << n - 6 * cnt[5];
    return 0;
}