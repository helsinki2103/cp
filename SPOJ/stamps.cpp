#include<bits/stdc++.h>

using namespace std;

int main(){
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; scanf("%d",&nTest);
    for(int iTest=1; iTest<=nTest; iTest++){
        printf("Scenario #%d:\n",iTest);
        int m, n; cin >> m >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        bool f = 0;
        int64_t ans = 0;
        for(int i=0; i<n; i++){
            ans += a[i];
            if (ans>=m){
                f = 1;
                printf("%d\n",i + 1);
                break;
            }
        }
        if (!f) printf("impossible\n");
        printf("\n");
    }
    return 0;
}