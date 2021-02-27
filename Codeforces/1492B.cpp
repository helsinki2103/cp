#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int> a(n, 0);
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            --a[i];
            cnt[a[i]]++;
        }
        
        int curmax = n - 1;
        deque<int> v;
        for (int i = n - 1; i >= 0; i--) {
            while (curmax >=0 && cnt[curmax] == 0) curmax--;
            if (curmax < 0) break;
            cnt[a[i]]--;
            v.push_front(a[i]);
            if (a[i] == curmax) {
                for (int x: v) cout << x + 1 << " ";
                v.clear();
            }
        }
        for (int x: v) cout << x + 1 << " ";
        cout << '\n';
    }
    return 0;
}