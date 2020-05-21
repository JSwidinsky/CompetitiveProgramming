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

/*
Number theory congruences
a few special cases, otherwise we just search for a number that is congruent to 3 mod n
*/
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  while(cin >> n && n) {
    if(n <= 2) {
      cout << "No such base" << endl;
      continue;
    }

    if(n == 3) {
      cout << 4 << endl;
      continue;
    }

    n -= 3;

    ll ans = (1ll << 40);
    for(ll i = 1; i*i <= n; ++i) {
      if(n % i == 0) {
        if(i >= 4) ans = min(ans, i);
        if(n/i >= 4) ans = min(ans, n/i);
      }
    }

    if(ans != (1ll << 40)) cout << ans << endl;
    else cout << "No such base" << endl;
  }
}

