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
const int d[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
const int inf = 1e9;

int dist[40][40][40][40];
int n, m;

struct State {
    int r1, c1, r2, c2;
    State(int _r1 = 0, int _c1 = 0, int _r2 = 0, int _c2 = 0) :
        r1(_r1), c1(_c1), r2(_r2), c2(_c2) {};
    bool operator == (const State &oth) const {
        return (r1 == oth.r1 && c1 == oth.c1 && r2 == oth.r2 && c2 == oth.c2);
    }
};

bool check(const State &cur, const State &nxt, vector<string> &plan) {
    if (nxt.r1 < 0 || nxt.r1 >= n)
        return false;
    if (nxt.c1 < 0 || nxt.c1 >= m)
        return false;
    if (nxt.r2 < 0 || nxt.r2 >= n)
        return false;
    if (nxt.c2 < 0 || nxt.c2 >= m)
        return false;
    if (plan[nxt.r1][nxt.c1] == '#' || plan[nxt.r2][nxt.c2] == '#')
        return false;
    if (nxt.r1 == nxt.r2 && nxt.c1 == nxt.c2)
        return false;
    if (cur.r1 == nxt.r2 && cur.c1 == nxt.c2 && cur.r2 == nxt.r1 && cur.c2 == nxt.c1)
        return false;
    return true;
}

class TwoRobots {
public:
    int move(vector<string> plan) {
        n = sz(plan);
        m = sz(plan[0]);
        State startState, endState;
        rep(i,n) {
            rep(j,m) {
                if (plan[i][j] == 'A') startState.r1 = i, startState.c1 = j;
                if (plan[i][j] == 'B') startState.r2 = i, startState.c2 = j;
                if (plan[i][j] == 'a') endState.r1 = i, endState.c1 = j;
                if (plan[i][j] == 'b') endState.r2 = i, endState.c2 = j;
            }
        }
        queue<State> q;
        q.push(startState);
        rep(i,n) rep(j,m) rep(i2,n) rep(j2,m) dist[i][j][i2][j2] = inf;
        dist[startState.r1][startState.c1][startState.r2][startState.c2] = 0;
        while (q.size()) {
            State cur = q.front();
            q.pop();
            if (cur == endState) return dist[cur.r1][cur.c1][cur.r2][cur.c2];
            rep(i,4) {
                rep(j,4) {
                    State nxt(cur.r1 + d[i][0], cur.c1 + d[i][1], cur.r2 + d[j][0], cur.c2 + d[j][1]);
                    if (!check(cur, nxt, plan)) continue;
                    if (mini(dist[nxt.r1][nxt.c1][nxt.r2][nxt.c2], dist[cur.r1][cur.c1][cur.r2][cur.c2] + 1)) {
                        q.push(nxt);
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    TwoRobots t;
    cout << t.move(	
{"#b#",
 "A.a",
 "#B#",
 "#.#"}
);
    return 0;
}