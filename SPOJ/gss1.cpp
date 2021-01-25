#include<bits/stdc++.h>

using namespace std;
const int N = 5e4 + 5;

struct SegTree{
    int sum, maxSum, maxLeft, maxRight;
};

SegTree st[N<<2];
int a[N];

int max(int a, int b, int c){
    return max(a, max(b, c));
}

int max(int a, int b, int c, int d){
    return max(a, b, max(c, d));
}

void build(int k, int l, int r){
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
    st[k].maxSum = max(st[k].sum, st[k<<1].maxSum, st[k<<1|1].maxSum, st[k<<1].maxLeft + st[k<<1|1].maxRight);
    st[k].maxSum = max(st[k].maxSum, st[k].maxLeft);
    st[k].maxSum = max(st[k].maxSum, st[k].maxRight);
}

SegTree query(int k, int l, int r, int u, int v){
    
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    return 0;
}