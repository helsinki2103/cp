#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

struct Trie
{
    int next[N][26], end[N];
    int sz = 0;
    void init()
    {
        memset(next,0,sizeof next);
        memset(end,0,sizeof end);
    }
    void insert(string s)
    {
        int v = 0;
        for (int i=0; i<s.size(); i++)
        {
            int c = s[i] - 'a';
            if (next[v][c]==0) next[v][c] = ++sz;
            v = next[v][c];
        }
        ++end[v];
    }

    bool find(string s)
    {
        int v = 0;
        for (int i=0; i<s.size(); i++)
        {
            int c = s[i] - 'a';
            if (next[v][c]==0) return false;
            v = next[v][c];
        }
        return end[v]>0;
    }
};

Trie trie;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int nTest; cin >> nTest;
    trie.init();
    while (nTest--)
    {
        int t; string s;
        cin >> t >> s;
        if (t==0) trie.insert(s);
        else cout << trie.find(s) << '\n';
    }
}