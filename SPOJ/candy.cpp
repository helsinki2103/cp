#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; 
    while (cin >> n && n!=-1){
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        int sum = accumulate(a.begin(), a.end(), 0);
        if (sum%n!=0){
            cout << -1 << '\n';
            continue;
        }
        int med = sum / n;
        int res = 0;
        for(int i=0; i<n; i++) res += max(0, a[i] - med);
        cout << res << '\n';
    }
    return 0;
}