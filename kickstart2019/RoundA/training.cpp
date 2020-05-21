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
    int n, p; cin >> n >> p;

    vector<ll> s(n);
    vector<ll> ps(n+5);

    for(int i = 0; i < n; ++i) {
      cin >> s[i];
    }

    sort(all(s));
    ps[0] = 0;
    ps[1] = s[0];
    for(int i = 2; i <= n; ++i) {
      ps[i] = ps[i-1] + s[i-1];
    }

    ll ans = 1ll << 50;
    for(int i = p-1; i < n; ++i) {
      ll sk = s[i]*p;
       
      ans = min(ans, sk - (ps[i+1]-ps[(i+1)-p]));
    }

    cout << "Case #" << ++c << ": " << ans << endl;
  }
}

