#include <bits/stdc++.h>
using namespace std;

const int b = 2000005;
int in[3000005];
int nonprime[b];
bool prime[b];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    for(int i = 2; i < b; ++i) {
        nonprime[i] += 1;
        if(!prime[i]) {
            for(int j = i*2; j < b; j += i) prime[j] = true;
        }
        else {
            for(int j = i; j < b; j += i) {
                ++(nonprime[j]);
            }
        }
    }

    int n; cin >> n;
    
    for(int i = 0; i < n; ++i) cin >> in[i];
    for(int i = 0; i < n; ++i) cout << nonprime[in[i]] << "\n";
}
