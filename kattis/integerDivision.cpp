#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
     int n, d; cin >> n >> d;

     map<int, ll> M;

     for(int i = 0; i < n; ++i){
          int m; cin >> m;
          M[m/d]++;
     }

     ll ans = 0;
     for(auto& p : M){
          ll m = p.second;
          ans += (m*(m-1)) / 2;
     }
     cout << ans << endl;
}

