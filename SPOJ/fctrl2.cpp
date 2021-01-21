#include<bits/stdc++.h>

using namespace std;

vector<int> to_vector(int x){
    vector<int> ans;
    while (x){
        ans.push_back(x%10);
        x/=10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> add(vector<int> a, vector<int> b){
    while (a.size()<b.size()) a.push_back(0);
    while (b.size()<a.size()) b.push_back(0);
    vector<int> ans;
    int r = 0;
    for(int i=0; i<a.size(); i++){
        int cur = a[i] + b[i] + r;
        ans.push_back(cur%10);
        r = cur / 10;
    }
    if (r) ans.push_back(r);
    return ans;
}

vector<int> mul(vector<int> a, vector<int> b){
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> ans;
    for(int i=0; i<a.size(); i++){
        int r = 0;
        vector<int> v;
        for(int j=0; j<i; j++) v.push_back(0);
        for(int j=0; j<b.size(); j++){
            int cur = a[i] * b[j] + r;
            v.push_back(cur%10);
            r = cur / 10;
        }
        if (r) v.push_back(r);
        ans = add(ans, v);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--){
        int n; cin >> n;
        vector<int> ans;
        ans.push_back(1);
        for(int i=2; i<=n; i++){
            ans = mul(ans, to_vector(i));
        }
        for(int x: ans) cout << x;
        cout << '\n';
    }
    return 0;
}