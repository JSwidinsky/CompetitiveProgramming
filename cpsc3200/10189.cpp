//brute force check by adding one to each adjacent tile that is a mine

#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

int n, m;
vector<string> grid;
vector<vector<int>> ans;

void check(int i, int j) {
  if(grid[i][j] != '*') return;
  
  for(int row : {-1, 0, 1}) {
    for(int col : {-1, 0, 1}) {
      if(i+row < 0 || i+row >= n) continue;
      if(j+col < 0 || j+col >= m) continue;
      ans[i+row][j+col]++;
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int count = 1; 
  while(cin >> n >> m && n != 0 && m != 0) {
    if(count != 1) cout << endl;
     grid.assign(n, "");
     ans.assign(n, vector<int>(m, 0));
     for(int i = 0; i < n; ++i) cin >> grid[i];

     for(int i = 0; i < n; ++i) {
       for(int j = 0; j < m; ++j) {
         check(i, j);
       }
     }
    
    cout << "Field #" << count++ << ":" << endl;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if(grid[i][j] == '*') cout << '*';
        else cout << ans[i][j];
      }
        
      cout << endl;
    }
  }
}

