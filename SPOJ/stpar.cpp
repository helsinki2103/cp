#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n;
    while (cin>>n && n){
        vector<int> a(n);
        for(int i=n-1; i>=0; i--) cin >> a[i];
        vector<int> temp;
        int cnt = 1, cur = 0;
        while (1){
            bool f = 0;
            if (temp.size() && temp.back()==cnt){
                ++cnt;
                temp.pop_back();
                continue;
            }
            while (a.size() && a.back()!=cnt){
                temp.push_back(a.back());
                a.pop_back();
            }
            if (a.size() && a.back()==cnt){
                f = 1;
                ++cnt;
                a.pop_back();
            }
            if (!f) break;
        }
        if (a.empty() && temp.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}