#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int inf = 1e6 + 5;

int calc(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 5;
    if (x == 5) return 2;
    if (x == 8) return 8;
    return inf;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int t; cin >> t;
    while (t--) {
        int h, m; cin >> h >> m;
        string s; cin >> s;
        string ans = "";
        int curh = (s[0] - '0') * 10 + (s[1] - '0');
        int curm = (s[3] - '0') * 10 + (s[4] - '0');
        bool f = 0;
        int t = -1;
        for(int i = curh; ; i = (i + 1) % h) {
            if (f) break;
            if (t == -1) {
                t = 1;
                for (int j = curm; j < m; j++) {
                    string nowh = to_string(i);
                    if (nowh.size() == 1) nowh = '0' + nowh;
                    string nowm = to_string(j);
                    if (nowm.size() == 1) nowm = '0' + nowm;
                    string now = nowh + nowm;
                    bool f2 = 1;
                    rep(k,sz(now)) {
                        f2 &= (now[k] == '0' || now[k] == '1' || now[k] == '2' || now[k] == '5' || now[k] == '8');
                    }
                    int refM = calc(now[1] - '0') * 10 + calc(now[0] - '0');
                    int refH = calc(now[3] - '0') * 10 + calc(now[2] - '0');
                    f2 &= (refH < h);
                    f2 &= (refM < m);
                    if (f2) {
                        f = 1;
                        ans = now;
                        // cout << (now[3] - '0') * 10 + (now[2] - '0') << '\n';
                        break;
                    }
                }
            } else {
                for (int j = 0; j < m; j++) {
                    string nowh = to_string(i);
                    if (nowh.size() == 1) nowh = '0' + nowh;
                    string nowm = to_string(j);
                    if (nowm.size() == 1) nowm = '0' + nowm;
                    string now = nowh + nowm;
                    bool f2 = 1;
                    rep(k,sz(now)) {
                        f2 &= (now[k] == '0' || now[k] == '1' || now[k] == '2' || now[k] == '5' || now[k] == '8');
                    }
                    int refM = calc(now[1] - '0') * 10 + calc(now[0] - '0');
                    int refH = calc(now[3] - '0') * 10 + calc(now[2] - '0');
                    f2 &= (refH < h);
                    f2 &= (refM < m);
                    if (f2) {
                        f = 1;
                        ans = now;
                        break;
                    }
                }
            }
        }
        cout << ans.substr(0,2) << ":" << ans.substr(2,2) << '\n';
    }
    return 0;
}