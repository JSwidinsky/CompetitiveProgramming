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

int n, k;
vector<vector<int>> A;

bool valid(int i, int j) {
  for(int r = 0; r < i; ++r) {
    if(A[r][j] == A[i][j]) return false; 
  }

  for(int c = 0; c < j; ++c) {
    if(A[i][c] == A[i][j]) return false;
  }

  return true;
}

bool solve(int i, int j, int t) {
  if(j == n) {
    i = i+1;
    j = 0;
  }

  if(i == n) return t == 0;
  
  bool ret = false;
  for(int c = 1; c <= n && !ret; ++c) {
    A[i][j] = c;
    if(valid(i,j)) {
      ret = ret || solve(i, j+1, (i == j ? t-c : t));
    }
  }
  
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;

  int c = 0;
  while(t--) {
    cin >> n >> k;
    
    A.assign(n, vector<int>(n));

    cout << "Case #" << ++c << ": ";
    if(solve(0, 0, k)) {
      cout << "POSSIBLE" << endl;

      for(auto& V: A) {
        for(auto x : V) cout << x << " ";
        cout << endl;
      }
    }
    else {
      cout << "IMPOSSIBLE" << endl;
    } 
  }
}

