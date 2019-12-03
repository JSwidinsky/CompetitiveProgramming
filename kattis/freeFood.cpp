#include <bits/stdc++.h>
using namespace std;

int main() {
     vector<pair<int, int>> V;
     int n; cin >> n;
     for(int i = 0; i < n; ++i) {
          int a, b; cin >> a >> b;
          V.push_back({a,b});
     }

     sort(V.begin(), V.end());
     
     pair<int, int> curr = V[0];
     long long int ans = 0;
     for(int i = 1; i < n; ++i) {
          pair<int,int> next = V[i];
          if(next.first >= curr.first && next.first <= curr.second) {
              curr.second = max(next.second, curr.second);
          }
          else {
            ans += abs(curr.first - curr.second) + 1;
            curr = next;
          }
     }
     ans += abs(curr.first - curr.second) + 1;
     cout << ans << endl;
}
