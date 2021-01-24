#include<bits/stdc++.h>

using namespace std;
const int M = 1e7 + 5;

int cnt[M];

int64_t getBIT(int x){
    int64_t ans = 0;
    for(;x<M;){
        ans += cnt[x];
        x += x&-x;
    }
    return ans;
}

void setBIT(int x){
    for(;x;){
        cnt[x]++;
        x -= x&-x;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--){
        int n; cin >> n;
        int64_t ans = 0;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            ans += getBIT(x + 1);
            setBIT(x);
        }
        cout << ans << '\n';
        memset(cnt,0,sizeof cnt);
    }
    return 0;
}