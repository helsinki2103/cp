#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
const int inf = 1e9 + 5;

int a[N];

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) a[i] = -1;
    a[0] = a[n + 1] = inf;
    int l = 1, r = n;
    while (l<=r){
        int x, y, z;
        int mid = (l + r) >> 1;
        if (a[mid] == -1){
            cout << "? " << mid << '\n';
            cout.flush();
            cin >> a[mid];
        }
        if (a[mid - 1] == -1){
            cout << "? " << mid - 1 << '\n';
            cout.flush();
            cin >> a[mid - 1];
        }
        if (a[mid + 1] == -1){
            cout << "? " << mid + 1 << '\n';
            cout.flush();
            cin >> a[mid + 1];
        }
        if (a[mid] < a[mid - 1] && a[mid] < a[mid + 1]){
            cout << "! " << mid << '\n';
            cout.flush();
            return 0;
        }
        if (a[mid - 1] < a[mid + 1]) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}