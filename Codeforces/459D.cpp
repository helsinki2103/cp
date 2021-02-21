#include<bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;

int tree1[N], tree2[N], tree[N];
int n;
int a[N], l[N], r[N];
map<int, int> mp;

int query1(int x) {
    int ans = 0;
    while (x) {
        ans += tree1[x];
        x -= (x & -x);
    }
    return ans;
}

int query2(int x) {
    int ans = 0;
    while (x < N) {
        ans += tree2[x];
        x += (x & -x);
    }
    return ans;
}

void update1(int x) {
    while (x < N) {
        tree1[x]++;
        x += (x & -x);
    }
}

void update2(int x) {
    while (x) {
        tree2[x]++;
        x -= (x & -x);
    }
}

int query(int x) {
    int ans = 0;
    while (x) {
        ans += tree[x];
        x -= (x & -x);
    }
    return ans;
}

void update(int x) {
    while (x < N) {
        tree[x]++;
        x += (x & -x);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(a[i]);
    int cnt = 0;
    for (int x: s) mp[x] = ++cnt;
    for (int i = 1; i <= n; i++) a[i] = mp[a[i]];
    memset(tree1,0,sizeof tree1);
    memset(tree2,0,sizeof tree2);
    for (int i = 1; i <= n; i++) {
        l[i] = i - query1(a[i] - 1) - query2(a[i] + 1);
        update1(a[i]);
        update2(a[i]);
    }
    memset(tree1,0,sizeof tree1);
    memset(tree2,0,sizeof tree2);
    for (int i = n; i >= 1; i--) {
        r[i] = n - i + 1 - query1(a[i] - 1) - query2(a[i] + 1);
        update1(a[i]);
        update2(a[i]);
    }
    // for (int i = 1; i <= n; i++) cout << l[i] << " ";
    // cout << '\n';
    // for (int i = 1; i <= n; i++) cout << r[i] << " ";
    memset(tree,0,sizeof tree);
    int64_t ans = 0;
    for (int i = n; i >= 1; i--) {
        ans += query(l[i] - 1);
        update(r[i]);
    }
    cout << ans;    
    return 0;
}