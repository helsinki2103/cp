#include<bits/stdc++.h>

using namespace std;
const int N = 5e4 + 5;
const int inf = 1e7;

struct SegTree{
    int sum, maxSum, maxLeft, maxRight;
};

SegTree st[N<<2];
int a[N];
int n, m;

int max(int a, int b, int c){
    return max(a, max(b, c));
}

int max(int a, int b, int c, int d){
    return max(a, b, max(c, d));
}

void build(int k, int l, int r){
    if (l>r) return;
    if (l==r){
        st[k].sum = st[k].maxSum = st[k].maxLeft = st[k].maxRight = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    st[k].sum = st[k<<1].sum + st[k<<1|1].sum;
    st[k].maxLeft = max(st[k<<1].maxLeft, st[k<<1].sum + st[k<<1|1].maxLeft);
    st[k].maxRight = max(st[k<<1|1].maxRight, st[k<<1|1].sum + st[k<<1].maxRight);
    st[k].maxSum = max(st[k].sum, st[k<<1].maxSum, st[k<<1|1].maxSum, st[k<<1].maxRight + st[k<<1|1].maxLeft);
    st[k].maxSum = max(st[k].maxSum, st[k].maxLeft);
    st[k].maxSum = max(st[k].maxSum, st[k].maxRight);
}

SegTree query(int k, int l, int r, int u, int v){
    if (r<u || l>v) return SegTree({-inf, -inf, -inf, -inf});
    if (l>=u && r<=v) return st[k];
    int mid = (l + r) >> 1;
    SegTree left = query(k<<1,l,mid,u,v);
    SegTree right = query(k<<1|1,mid+1,r,u,v);
    SegTree ans({0, 0, 0, 0});
    ans.sum = left.sum + right.sum;
    ans.maxLeft = max(left.maxLeft, left.sum + right.maxLeft);
    ans.maxRight = max(right.maxRight, right.sum + left.maxRight);
    ans.maxSum = max(ans.sum, left.maxSum, right.maxSum, left.maxRight + right.maxLeft);
    ans.maxSum = max(ans.maxSum, ans.maxLeft);
    ans.maxSum = max(ans.maxSum, ans.maxRight);
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    build(1,1,n);
    cin >> m;
    while (m--){
        int u, v; cin >> u >> v;
        cout << query(1,1,n,u,v).maxSum << '\n';
    }
    return 0;
}