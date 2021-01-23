#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, c; 
    while (scanf("%d %d %d",&a,&b,&c) && (a || b || c)){
        if (b - a == c - b && a!=b){
            cout << "AP " << c + c - b << '\n';
        }
        else{
            cout << "GP ";
            if (b==0) b = 1;
            cout << c * c / b << '\n';
        }
    }
    return 0;
}