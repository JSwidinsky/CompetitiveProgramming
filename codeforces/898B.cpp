#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << ": " << a << endl;

typedef long long int ll;

int main() {
    ll a, b, n;
    cin >> n >> a >> b;

    ll x = 0;
    while(n - a*x >= 0) {
        if((n - a*x) % b == 0) {
            cout << "YES" << endl;
            cout << x << " " << (n - a*x)/b << endl;
            return 0;
        }
        ++x;
    }
    cout << "NO" << endl;
}
