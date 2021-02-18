#include<bits/stdc++.h>

using namespace std;
const int N = 1e2 + 5;

int st[N << 2];
int n;
int a[N];
int h[N];

void build(int l, int r, int c = 0) {
    if (l == r) {
        h[l] = c;
        return;
    }
    int mx = -1, id = -1;
    for (int i = l; i <= r; i++) {
        if (a[i] > mx) {
            mx = a[i];
            id = i;
        }
    }
    if (id == - 1) return;
    h[id] = c;
    build(l,id-1,c + 1);
    build(id+1,r,c + 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        build(1,n);
        for (int i = 1; i <= n; i++) cout << h[i] << " ";
        cout << '\n';
    }
    return 0;
}