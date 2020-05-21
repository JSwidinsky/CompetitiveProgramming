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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  int c = 0;
  while(t--) {
    int n; cin >> n;
    vector<vector<int>> V(n, vector<int>(n));

    for(auto& A : V) for(auto& x : A) cin >> x;
    
    int trace = 0;
    for(int i = 0; i < n; ++i) trace += V[i][i];

    int col = 0;
    int row = 0;
    for(int i = 0; i < n; ++i) {
      vector<int> A(n+5, 0);
      for(int j = 0; j < n; ++j) {
        if(A[V[i][j]]) {
          ++row;
          break;
        }
        A[V[i][j]] = 1;
      }
    }

    for(int j = 0; j < n; ++j) {
      vector<int> A(n+5, 0);
      for(int i = 0; i < n; ++i) {
        if(A[V[i][j]]) {
          ++col;
          break;
        }
        A[V[i][j]] = 1;
      }
    }
    
    cout << "Case #" << ++c << ": " << trace << " " << row << " " << col << endl;
  }
}

