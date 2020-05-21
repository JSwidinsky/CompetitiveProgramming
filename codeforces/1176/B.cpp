#include <bits/stdc++.h>
using namespace std;

int main() {
     int t; cin >> t;
     while(t--) {
          int n; cin >> n;
          vector<int> A(n);

          for(int& x : A) { cin >> x; x = x % 3; }

          int zero = 0, one = 0, two = 0;

          for(int& a : A) {
               if(a == 0) ++zero;
               if(a == 1) ++one;
               if(a == 2) ++two;
          }

          int ans = zero;

          int m = min(one, two);

          one -= m; two -= m;
          ans += m;
          
          if(one) {
               ans += (one / 3);
          }
          else {
               ans += (two / 3);
          }
          

          cout << ans << endl;
          
     }
}