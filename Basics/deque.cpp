#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

int a[N], l[N], r[N];
int n;
int ans, ansL, ansR;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--){
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++){
            l[i] = i;
            while (l[i] > 1 && a[l[i] - 1] >= a[i]) l[i] = l[l[i] - 1];
        }
        for(int i=n; i>=1; i--){
            r[i] = i;
            while (r[i] < n && a[r[i] + 1] >= a[i]) r[i] = r[r[i] + 1];
        }
        ans = -1;
        for(int i=1; i<=n; i++){
            if ((r[i] - l[i] + 1) * a[i] > ans){
                ans = (r[i] - l[i] + 1) * a[i];
                ansL = l[i];
                ansR = r[i];
            }
        }
        cout << ans << " " << ansL << " " << ansR << '\n';
    }
    
    return 0;
}