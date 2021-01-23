#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

string s, t;
int n, k, sz = 0, res = 0;
int pref[1555];
int fin[N], nxt[N][26];
bool created[N];

void add(string cur)
{
    int v = 0;
    for (int i=0; i<cur.size(); i++)
    {
        int c = cur[i] - 'a';
        if (!created[nxt[v][c]])
        {
            nxt[v][c] = ++sz;
            created[sz] = 1;
        }
        v = nxt[v][c];
    }
    ++fin[v];
}

bool check(string cur)
{
    int v = 0;
    for (int i=0; i<cur.size(); i++)
    {
        int c = cur[i] - 'a';
        if (!created[nxt[v][c]]) return false;
        v = nxt[v][c];
    }
    return fin[v]>0;
}

int main()
{
    cin >> s >> t >> k;
    n = s.size();
    s = ' ' + s;
    pref[0] = 0;
    for (int i=1; i<=n; i++)
    {
        pref[i] = pref[i - 1];
        if (t[s[i] - 'a']=='0') pref[i]++;
    }
    memset(created,false,sizeof created);
    for (int i=1; i<=n; i++)
    {
        for (int j=i; j<=n; j++)
        {
            if (pref[j] - pref[i - 1] > k) continue;
            if (!check(s.substr(i, j - i + 1))) 
            {
                res++;
                add(s.substr(i, j - i + 1));
            }
        }
    }
    cout << res;
}