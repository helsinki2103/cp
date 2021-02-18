#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<string, int> mp;
    string ans = "";
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (ans.size()) continue;
        if (s[0] != '!') {
            if (mp[s] == 2) {
                ans = s;
            }   else mp[s] = 1;
        } else {
            s.erase(0, 1);
            if (mp[s] == 1) {
                ans = s;
            } else mp[s] = 2;
        }
    }
    if (ans.size()) cout << ans << '\n';
    else cout << "satisfiable\n";
    return 0;
}