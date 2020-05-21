//shortest path/greedy?

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



int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m;
  while(cin >> n >> m) {
    vector<vector<int>> A(n, vector<int>(m));
    
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        cin >> A[i][j]; 
      }
    }

    vector<vector<pair<int, int>>> path(n, vector<pair<int, int>>(m, {0, 0}));

    for(int j = m-1; j >= 0; --j) {
      for(int i = 0; i < n; ++i) {
        if(j == m-1) path[i][j] = {A[i][j], -1};
        else {
          pair<int, int> val = {path[(i-1+n)%n][j+1].first + A[i][j], (i-1+n)%n};
          
          if(path[i][j+1].first + A[i][j] < val.first || (path[i][j+1].first + A[i][j] == val.first && i < val.second)) val = {path[i][j+1].first + A[i][j], i};
          
          int up = (i+1)%n;
          if(path[up][j+1].first + A[i][j] < val.first || (path[up][j+1].first + A[i][j] == val.first && up < val.second)) val = {path[up][j+1].first + A[i][j], up};
          
          path[i][j] = val;
        }
      }
    }

    int minimum = path[0][0].first;
    int start = 0;
    for(int i = 1; i < n; ++i) {
      if(path[i][0].first < minimum) {
        minimum = path[i][0].first;
        start = i;
      }
    }

    int next = start;
    for(int j = 0; j < m; ++j) {
      cout << next+1 << (j+1 == m ? "" : " ");
      if(j+1 != m) next = path[next][j].second;
    }
    cout << endl;

    cout << minimum << endl;
  }
}

