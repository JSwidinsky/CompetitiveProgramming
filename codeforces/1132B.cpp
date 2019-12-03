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

typedef long long int ll;

int C[300005];
ll ps[300005];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  for(int i = 0; i < n; ++i) cin >> C[i];

  sort(C, C+n, [](int a, int b) -> bool { return a > b; });

  ps[0] = C[0];
  for(int i = 1; i < n; ++i) { ps[i] = ps[i-1] + C[i]; }

  int m; cin >> m;
  while(m--) {
    int c; cin >> c;
    --c;
    ll cost = ps[c-1];
    ll ans = cost + (ps[n-1] - ps[c]);

    cout << ans << endl;
  }
}

