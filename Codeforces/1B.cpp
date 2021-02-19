#include<bits/stdc++.h>

using namespace std;
const char ch[] = {'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        bool f = 0;
        int k = s.find('C');
        if (k != -1) {
            if (s[0] == 'R' && k != 1) {
                f = 1;
                for (int i = 1; i < k; i++) if (s[i] < '0' || s[i] > '9') {
                    f = 0;
                    break;
                }
                for (int i = k + 1; i < s.size(); i++) if (s[i] < '0' || s[i] > '9') {
                    f = 0;
                    break;
                }
            }
        }
        if (f) {
            s.erase(0,1);
            int id = s.size() - 1;
            while (s[id] != 'C') id--;
            int64_t col = 0;
            for (int i = id + 1; i < s.size(); i++) col = col * 10 + (s[i] - '0');
            string c = "";
            int x = col;
            while (x) {
                int r = x % 26;
                c = ch[r] + c;
                x -= r;
                x /= 26;
                if (r == 0) x--;
            }
            cout << c << s.substr(0,id) << '\n';
        } else {
            int id = 0;
            while (s[id] >= 'A' && s[id] <= 'Z') id++;
            int64_t num = 0;

            int tmp = 1;
            for (int i = 0; i < id; i++) {
                num = num * 26 + (s[i] - 'A' + 1);
                // tmp *= 26;
            }
            cout << "R" << s.substr(id) << "C" << num << '\n';
        }
    }
    return 0;
}   