#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
const int N = 87000000;

vector<int> prime;
bitset<N> filter(0);

void init()
{
        int i;
        for (i=2; i*i<N; i++)
        {
                if (!filter[i])
                {
                        prime.push_back(i);
                        for (int j=i; j<N; j+=i) filter[j] = 1;
                }
        }
        for (; i<N; i++)
        {
                if (!filter[i])
                {
                        prime.push_back(i);
                        filter[i] = 1;
                }
        }
}

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        init();
        int q; cin >> q;
        while (q--)
        {
                int x; cin >> x;
                cout << prime[x-1] << '\n';
        }
        return 0;
}
