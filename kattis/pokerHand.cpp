#include <bits/stdc++.h>
using namespace std;

int A[20];

int main() {
     char c;
     for(int i = 0; i < 5; ++i)
     {
          cin >> c;
          if(c == 'J') A[11]++;
          else if(c == 'Q') A[12]++;
          else if(c == 'K') A[13]++;
          else if(c == 'A') A[0]++;
          else if(c == 'T') A[10]++;
          else A[c - '0']++;

          cin >> c;
     }

     int ans = 1;
     for(int i = 0; i <= 13; ++i) ans = max(ans, A[i]);
     cout << ans << endl;
}