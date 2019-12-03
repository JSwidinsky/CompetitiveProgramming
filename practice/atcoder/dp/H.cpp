#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int h, w;
char c[1005][1005];
const ll mod = 1000000007;

ll dp[1005][1005];

ll f(int H, int W)
{
    ll& x = dp[H][W];
    if(x != -1) return x;

    if(H == h && W == w) return 1;
    if(c[H][W] == '#') return x = 0;

    if(H+1 > h) return x = f(H, W+1) % mod;
    if(W+1 > w) return x = f(H+1, W) % mod;

    return x = (f(H, W+1) + f(H+1, W)) % mod;
}

int main()
{
    cin >> h >> w;
    for(int i = 1; i <= h; ++i)
        for(int j = 1; j <= w; ++j)
            { cin >> c[i][j]; dp[i][j] = -1; }
    dp[h][w] = 1;

    cout << f(1,1) << endl;    
    
}



