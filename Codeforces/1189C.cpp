#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

int st[N << 2];
int n, a[N];

/* solution 1: segment tree
void build(int k, int l, int r) {
    if (l == r) {
        st[k] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    st[k] = st[k<<1] + st[k<<1|1];
}

int get(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[k];
    int mid = (l + r) >> 1;
    return get(k<<1,l,mid,u,v) + get(k<<1|1,mid+1,r,u,v);
}
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int q; cin >> q;
    // solution 2: prefix sum   
    while (q--) {
        int l, r; cin >> l >> r;
        cout << (a[r] - a[l - 1])/10 << '\n';
    }
    return 0;
}