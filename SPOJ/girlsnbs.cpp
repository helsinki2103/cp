#include<bits/stdc++.h>

using namespace std;

int max(int a, int b, int c, int d){
    return max(max(a, b), max(c, d));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int x, y;
    while (cin >> x >> y && x!=-1 && y!=-1){
        if (x==0 && y==0){
            cout << 0 << '\n';
            continue;
        }
        if (x<y) swap(x, y);
        cout << (x - 1)/(y + 1) + 1 << '\n';
    }
    return 0;
}