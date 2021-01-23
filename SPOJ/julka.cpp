#include<bits/stdc++.h>

using namespace std;

string sub(string a, string b){
    string ans = "";
    while (b.size()<a.size()) b.insert(0, "0");
    int r = 0;
    for(int i=a.size()-1; i>=0; i--){
        int cur = (int)(a[i] - '0') - (r + (int)(b[i] - '0'));
        if (cur<0) r = 1, cur += 10;
        else r = 0;
        ans += (char)(abs(cur) + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string div(string a, int b){
    string ans = "";
    int r = 0;
    for(int i=0; i<a.size(); i++){
        int cur = r * 10 + (int)(a[i] - '0');
        ans += (char)(cur/b + '0');
        r = cur%b;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    string a, b;
    while (cin>>a>>b){
        string y = div(sub(a, b), 2);
        string x = sub(a, y);
        while (x.size() && x[0]=='0') x.erase(0, 1);
        while (y.size() && y[0]=='0') y.erase(0, 1);
        cout << x << '\n' << y << '\n';
    }
    return 0;
}