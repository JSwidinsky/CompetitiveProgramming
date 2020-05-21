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

typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll c, n;
  cin >> c >> n;

  ll curr = 0;
  for(int i = 0; i < n; ++i) {
    int leave, enter, stay;
    cin >> leave >> enter >> stay;
    if(leave > curr) { cout << "impossible" << endl; return 0; }

    curr -= leave;

    if(curr + enter > c) { cout << "impossible" << endl; return 0; }
    curr += enter;

    if(curr < c && stay) { cout << "impossible" << endl; return 0; }
  }
  
  if(curr) cout << "impossible" << endl;
  else cout << "possible" << endl;
}

