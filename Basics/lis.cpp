#include<bits/stdc++.h>

using namespace std;
const int inf = 1e9;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n; cin >> n;
    int ans = 0;
    vector<int> l(n + 1, inf);
    for(int i=0; i<n; i++){
        int x; cin >> x;
        int pos = lower_bound(l.begin(), l.end(), x) - l.begin();
        l[pos] = x;
        ans = max(ans, pos);
    }
    cout << ans + 1;
    return 0;
}