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

typedef pair<pair<int, int>, int> pii;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  int c = -1;
  while(t--) {
    if(++c) cout << endl;

    int n; cin >> n;
    vector<pii> V(n);
    for(int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      V[i] = {{a, b}, i+1};
    }

    sort(all(V), [](pii& a, pii& b) {
      return a.first.second * b.first.first > a.first.first * b.first.second;
    });
    
    int c2 = n;
    for(auto& p : V) {
      cout << p.second << (--c2 ? " " : "");
    }
    cout << endl;
  }
}

