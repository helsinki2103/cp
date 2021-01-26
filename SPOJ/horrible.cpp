#include<bits/stdc++.h>

using namespace std;
const int64_t N = 1e5 + 5;

struct SegTree{
    int64_t val, lazy;
};

SegTree st[N<<2];

void build(int64_t k, int64_t l, int64_t r){
    if (l>r) return;
    if (l==r){
        st[k].val = st[k].lazy = 0;
        return;
    }
    int64_t mid = (l + r) >> 1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    st[k].val = 0;
    st[k].lazy = 0;
}

void update(int64_t k, int64_t l, int64_t r, int64_t u, int64_t v, int64_t w){
    if (l>v || r<u) return;
    if (l>=u && r<=v){
        st[k].val += (r - l + 1) * w;
        st[k].lazy += w;
        return;
    }
    int64_t mid = (l + r) >> 1;
    update(k<<1,l,mid,u,v,w);
    update(k<<1|1,mid+1,r,u,v,w);
    st[k].val = st[k<<1].val + st[k<<1|1].val + (r - l + 1) * st[k].lazy;
}

int64_t query(int64_t k, int64_t l, int64_t r, int64_t u, int64_t v, int64_t lz){
    if (l>v || r<u) return 0;
    if (l>=u && r<=v) return (st[k].val + (r - l + 1) * lz);
    int64_t mid = (l + r) >> 1;
    return query(k<<1,l,mid,u,v,lz + st[k].lazy) + query(k<<1|1,mid+1,r,u,v,lz + st[k].lazy);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int64_t nTest; cin >> nTest;
    while (nTest--){
        int64_t n, q; cin >> n >> q;
        build(1,1,n);
        while (q--){
            int64_t t; cin >> t;
            if (t){ 
                int64_t u, v; cin >> u >> v;
                cout << query(1,1,n,u,v,0) << '\n';
            }
            else{
                int64_t u, v;
                int64_t w; 
                cin >> u >> v >> w;
                update(1,1,n,u,v,w);
            }
        }
    }
    return 0;
}