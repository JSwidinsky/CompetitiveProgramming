//use a multiset, pick the first and last elements in the set, add their values, delete them


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
  int n;
  while(cin >> n && n) {
    multiset<int> S;

    long long ans = 0;
    for(int i = 0; i < n; ++i) {
      int m; cin >> m;
      for(int j = 0; j < m; ++j) {
        int a; cin >> a;
        S.insert(a);
      }

      auto h = --(S.end()), l = (S.begin());
      
      ans += (*h - *l);
      S.erase(h); S.erase(l);  
    }

    cout << ans << endl;
  }
}

