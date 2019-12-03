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
    int n; cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; ++i) cin >> A[i];

    map<int, int> M;
    int ans = 1 << 30;
    bool b = false;
    for(int i = 0; i < n; ++i) {
      if(M.count(A[i])) {
        b = true;
        ans = min(ans, abs(M[A[i]] - i) + 1);
      }
      
      M[A[i]] = i;
    }

    if(b) {
      cout << ans << endl;
    }
    else cout << -1 << endl;
  }
}

