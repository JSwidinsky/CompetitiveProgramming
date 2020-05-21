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

typedef unsigned long long int ull;

//A[n][m] = n choose m
ull A[32][32];

/*
Compute all n choose r for n and r up to 30, then just print n choose m-1
*/


int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  for(int i = 0; i <= 30; ++i) {
    for(int j = 0; j <= i; ++j) {
      if(j == 0 || j == i) A[i][j] = 1;
      else A[i][j] = A[i-1][j-1] + A[i-1][j];
    }
  }

  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    cout << A[n][m-1] << endl;
  }
}

