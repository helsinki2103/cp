#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define fore(i,a,b) for (int i = (a); i <= (b); i++)
#define ford(i,a,b) for (int i = (a); i >= (b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

class GoldMining {
public: 
    const ll inf = 1e18;
    long maxProfit(long goldInGround, long miningTime, long hiringCost) {
        long ans = min(goldInGround, miningTime);
        long empl = 1;
        long cur = 0;
        auto calc = [&] (int i, long c, long e, long g, long mid) {
            if (mid < 0) return -inf;
            return c - mid * hiringCost + min((miningTime - long(i) + 1) * (e + mid), g);
        };
        fore(i,1,miningTime) {
            long l = 0, r = cur / hiringCost;
            long nxt = -1;
            while (l <= r) {
                long mid = (l + r) >> 1ll;
                if (calc(i, cur, empl, goldInGround, mid) > calc(i, cur, empl, goldInGround, mid - 1)) {
                    nxt = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (nxt != -1) {
                maxi(ans, cur - nxt * hiringCost + min((miningTime - long(i) + 1) * (empl + nxt), goldInGround));
                empl += nxt;
                cur -= nxt * hiringCost;
            }
            if (goldInGround > empl) {
                cur += empl;
                goldInGround -= empl;
            } else {
                cur += goldInGround;
                break;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    GoldMining t;
    cout << t.maxProfit(987654321098765432, 100, 3);
    return 0;
}