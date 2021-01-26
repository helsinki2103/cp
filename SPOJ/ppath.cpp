#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
bool vis[10001];

bool isPrime(int x)
{
    if (x<=1) return 0;
    if (x<=3) return 1;
    for (int i=2; i*i<=x; i++) if (x%i==0) return 0;
    return 1;
}

bool getNum(int a, int b, int c, int d, int &num)
{
    num = 0;
    if (a==0) return false;
    num = a*1000 + b*100 + c*10 + d;
    return isPrime(num);
}

int bfs(int sx, int sy)
{
    memset(vis,0,sizeof vis); vis[sx] = 1;
    int res = 0; queue<pi> q; q.push({sx, 0});
    while (q.size())
    {
        int u = q.front().first; int w = q.front().second; q.pop();
        if (u==sy) return w;
        int num;
        int d = u%10; u/=10;
        int c = u%10; u/=10;
        int b = u%10; u/=10;
        int a = u%10;
        for (int i=0; i<=9; i++)
        {
            if (i!=a) 
            {
                if (getNum(i, b, c, d, num) && !vis[num]) q.push({num, w + 1}), vis[num] = 1;
            }
            if (i!=b)
            {
                if (getNum(a, i, c, d, num) && !vis[num]) q.push({num, w + 1}), vis[num] = 1;
            }
            if (i!=c) 
            {
                if (getNum(a, b, i, d, num) && !vis[num]) q.push({num, w + 1}), vis[num] = 1; 
            }
            if (i!=d)
            {
                if (getNum(a, b, c, i, num) && !vis[num]) q.push({num, w + 1}), vis[num] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("ppath.inp","r",stdin);
    int nTest; cin >> nTest;
    while (nTest--)
    {
        int x, y; cin >> x >> y;
        cout << bfs(x, y) << '\n';
    }
}
