#include<bits/stdc++.h>

using namespace std;

string sub(string a, string b){
    while (a.size()<b.size()) a.insert(0, "0");
    while (b.size()<a.size()) b.insert(0, "0");
    int r = 0;
    string ans = "";
    for(int i=a.size()-1; i>=0; i--){
        int cur = a[i] - b[i] - r;
        r = 0;
        if (cur<0){
            r = 1;
            cur += 10;
        }
        ans += (char)(cur + '0');
    }
    reverse(ans.begin(),ans.end());
    while (ans[0]=='0') ans.erase(0, 1);
    return ans;
}

string add(string a, string b){
    while (a.size()<b.size()) a.insert(0, "0");
    while (b.size()<a.size()) b.insert(0, "0");
    int r = 0;
    string ans = "";
    for(int i=a.size()-1; i>=0; i--){
        int cur = r + (a[i] - '0') + (b[i] - '0');
        r = 0;
        if (cur>=10){
            cur %= 10;
            r = 1;
        }
        ans += (char)(cur + '0');
    }
    if (r) ans += "1";
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--){
        string a, b, c, d, e; cin >> a >> b >> c >> d >> e;
        if (a.find("machula")!=-1){
            cout << sub(e, c) << " + " << c << " = " << e << '\n';
        }
        else if (c.find("machula")!=-1){
            cout << a << " + " << sub(e, a) << " = " << e << '\n';
        }
        else{
            cout << a << " + " << c << " = " << add(a, c) << '\n';
        }
    }
    return 0;
}