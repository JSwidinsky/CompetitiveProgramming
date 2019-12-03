#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n; cin >> n;

     vector<vector<int>> A(n+5), B(n+5);

     A[0] = B[0] = vector<int>({0,0,0,0});
     for(int i = 1; i <= n; ++i){
          A[i] = vector<int>(4);
          for(int j = 0; j < 4; ++j){
               cin >> A[i][j];
          }
     }

     for(int i = 1; i <= n; ++i){
          B[i] = vector<int>(4);
          for(int j = 0; j < 4; ++j){
               cin >> B[i][j];
          }
     }

     bool possible = false;
     bool yes = true;

     queue<pair<int, int>> Q;
     Q.push({1,1});
     set<pair<int,int>> S;

     while(!Q.empty()){
          pair<int, int> p = Q.front(); Q.pop();
          int a = p.first, b = p.second;

          if(S.count({a,b})) continue;
          S.insert({a,b});

          if(a == n){
               possible = true;
          }
          if(a == n && b != n){
               yes = false;
          }

          for(int i = 0; i < 4; ++i){
               Q.push({A[a][i], B[b][i]});
          }
     }

     if(possible){
          if(yes){
               cout << "Yes" << endl;
          }
          else{
               cout << "No" << endl;
          }
     }
     else{
          cout << "Impossible" << endl;
     }
}