#include<bits/stdc++.h>

using namespace std;

class CoolPairsEasy {
public:
    int count(vector<string> firstname, vector<string> lastname) {
        int n = firstname.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                ans += lastname[i] == firstname[j];
            }
        }
        return ans;
    }
};

// int main() {
//     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     vector<string> fn, ln;
//     fn = {"elton", "tom", "john"};
//     ln = {"john", "jones", "cena"};
//     CoolPairsEasy cpe;
//     cout << cpe.count(fn, ln);
//     return 0;
// }