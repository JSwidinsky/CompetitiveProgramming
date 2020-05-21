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
    vector<pair<int, int>> A(n);
    for(int i = 0; i < n; ++i) { int a; cin >> a; A[i] = {a, i}; };

    sort(all(A));

    //debug(A);
    
    //vector<bool> ans(n+1, false);
    //ans[0] = true;
    cout << 1;
    int mmin = A[0].second, mmax = A[0].second;
    for(int i = 1; i < n; ++i) {
      mmin = min(mmin, A[i].second);
      mmax = max(mmax, A[i].second);

      if((mmax - mmin) + 1 == i+1) cout << 1;
      else cout << 0;
    }
    cout << endl;
  }
}

