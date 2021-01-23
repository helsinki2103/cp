#include<bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        string s; cin >> s;
        vector<char> sign;
        vector<char> ans;
        for(int i=0; i<s.size(); i++){
            if (s[i]=='(') continue;
            if (s[i]>='a' && s[i]<='z') ans.push_back(s[i]);
            if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^') sign.push_back(s[i]);
            if (s[i]==')'){
                ans.push_back(sign.back());
                sign.pop_back();
            }
        }
        for(char c: ans) cout << c;
        cout << '\n';
    }
    return 0;
}