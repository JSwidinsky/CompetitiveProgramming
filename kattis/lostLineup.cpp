#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n; cin >> n;
     vector<pair<int,int>> V;
     V.push_back({-1, 1});
     for(int i = 0; i < n-1; ++i){
          int a; cin >> a;
          V.push_back({a, i+2});
     }

     sort(V.begin(), V.end());

     for(auto& p : V){
          cout << p.second << " ";
     }
     cout << endl;
}