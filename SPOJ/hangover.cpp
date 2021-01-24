#include<bits/stdc++.h>
#define ld long double

using namespace std;
const ld EPS = 1e-18;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    vector<ld> v;
    int cnt = 2;
    v.push_back((ld)(1/(ld)cnt));
    for(int i=0; i<100000; i++){
        ++cnt;
        v.push_back(v.back() + (ld)(1/(ld)cnt));
    }
    ld x;
    while (cin>>x && x!=0.00){
        int i = 0, j = 99999;
        while (i<j){
            int mid = (i + j) >> 1;
            //cout << v[mid] << " ";
            if (v[mid]<x) i = mid + 1;
            else{
                j = mid;
            }
        }
        cout << j + 1 << " card(s)" << '\n';
    }
    return 0;
}