#include <bits/stdc++.h>
using namespace std;

int A[86400*2+2];

int main() {
     int n, p, d;
     cin >> n >> p >> d;
     string s; cin >> s;

     s = s + s;

     if(s[0] == 'Z') A[0] = 1;
     for(int i = 1; i < s.length(); ++i){
          if(s[i] == 'Z') A[i] = A[i-1] + 1;
          else A[i] = A[i-1];
     }

     long long int ans = 0;
     for(int i = n; i < s.length(); ++i){
          if(abs(A[i] - A[i-p]) < d) ++ans;
     }

     cout << ans << endl;
}