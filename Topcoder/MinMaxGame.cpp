#include<bits/stdc++.h>

using namespace std;

class MinMaxGame {
public:
    int lastNumber(vector<int> a) {
        int n = a.size();
        if (n & 1) return max(a.front(), a.back());
        return min(a.front(), a.back());
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    MinMaxGame test;
    cout << test.lastNumber({4, 5, 1, 6, 5});
    return 0;
}