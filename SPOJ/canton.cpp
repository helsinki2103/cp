#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; scanf("%d",&nTest);
    while (nTest--){
        int x; scanf("%d",&x);
        int l = 0, r = 4e4 + 5;
        while (l<=r){
            int mid = (l + r) >> 1;
            if (mid*(mid + 1)>=2*x){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        int t = x - r * (r + 1) / 2;
        printf("TERM %d IS ",x);
        if ((r + 1)&1) printf("%d/%d\n",r+2-t,t);
        else printf("%d/%d\n",t,r+2-t);
    }
    return 0;
}