#include <bits/stdc++.h>
using namespace std;

int main() {

     int t; cin >> t;
     while(t--) {
          long long int a; cin >> a;
          
          long long int ans = 0;
          bool p = true;
          while(a != 1 && p) {
               if(a % 2 == 0) {
                    a /= 2;
               }
               else if(a % 3 == 0) {
                    a = (a / 3) * 2;
               }
               else if(a % 5 == 0) {
                    a = (a / 5) * 4;
               }
               else {
                    p = false;
               }

               ++ans;
          }

          cout << (p ? ans : -1) << endl;
     }
}