#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, k; cin >> n >> k;
        string s, t; cin >> s >> t;
        vector<int> cnts(26, 0), cntt(26, 0);
        for (int i = 0; i < s.size(); i++) cnts[s[i] - 'a']++;
        for (int i = 0; i < t.size(); i++) cntt[t[i] - 'a']++;
        int sum = 0;
        bool f = 1;
        for (int i = 0; i < 26; i++) {
            sum += cnts[i];
            if (sum >= cntt[i]) sum -= cntt[i];
            else {
                f = 0;
                break;
            }
            if (sum % k != 0) {
                f = 0;
                break;
            }
        }
        if (sum != 0) f = 0;
        cout << (f ? "Yes\n" : "No\n");
    }
    return 0;
}