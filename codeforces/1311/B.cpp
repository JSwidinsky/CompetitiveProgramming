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

  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<int> A(n), P(m);

    for(int& x : A) cin >> x;
    for(int& x : P) { cin >> x; --x; }

    sort(all(P));

    for(int i = 0; i < n; ++i) {
      for(int j : P) {
        if(A[j] > A[j+1]) swap(A[j], A[j+1]);
      }
    }

    bool b = true;
    for(int i = 0; i < n-1; ++i) {
      if(A[i] > A[i+1]) b = false;
    }

    cout << (b ? "YES" : "NO") << endl;
  }

}

