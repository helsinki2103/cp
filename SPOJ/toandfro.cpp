#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    int n;
    while (cin >> n && n){
        char c[205][n];
        string s; cin >> s;
        int nxt = 1, curRow = -1, curCol = 0;
        for(int i=0; i<s.size(); i++){
            if (curCol==0 || curCol==n - 1){
                if (nxt==0){
                    if (curCol==n-1) nxt = -1;
                    else nxt = 1;
                }
                else{
                    curRow++;
                    nxt = 0;
                }
            }
            curCol += nxt;
            c[curRow][curCol] = s[i];
        }
        for(int j=0; j<n; j++){
            for(int i=0; i<=curRow; i++) cout << c[i][j];
        }
        cout << '\n';
    }
    return 0;
}