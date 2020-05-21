#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;

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

/*
Just an implementation problem
*/


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while(t--) {
    int r, c; cin >> r >> c;
    
    vector<vector<int>> grid(r, vector<int>(c));
    for(auto& A : grid) for(auto& x : A) { char c; cin >> c; x = (int)(c-'0'); }

    set<int> row, col;
    for(int i = 0; i < r; ++i) {
      for(int j = 0; j < c; ++j) {
        if(grid[i][j]) {
          row.insert(i);
          col.insert(j);
        }
      }
    }

    int b = true;
    for(int i : row) {
      for(int j : col) {
        if(!grid[i][j] && b) {
          cout << "impossible" << endl;
          b = false;
        }
      }
    }

    if(b) {
      if(row.size() <= 1 || col.size() <= 1) {
        for(int i = 0; i < r; ++i)
          for(int j = 0; j < c; ++j)
            cout << (grid[i][j] ? 'P' : 'N') << (j == c-1 ? "\n": "");
      }
      else {
        for(int i = 0; i < r; ++i)
          for(int j = 0; j < c; ++j)
            cout << (grid[i][j] ? 'I' : 'N') << (j == c-1 ? "\n" : ""); 
      }
    }

    cout << string(10, '-') << endl;
  }
}

