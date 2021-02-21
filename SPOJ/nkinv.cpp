#include<bits/stdc++.h>

using namespace std;
const int N = 6e4 + 5;

int tree[N];
int n;

int query(int x) {
    int ans = 0;
    while (x < N) {
        ans += tree[x];
        x += (x & -x);
    }
    return ans;
}

void update(int x) {
    while (x) {
        tree[x]++;
        x -= (x & -x);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ans += query(x + 1);
        update(x);
    }
    cout << ans;
    return 0;
}