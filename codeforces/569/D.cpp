#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define FOR(s, n) for(int i = s; i < n; ++i)

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

int n;
const ll M = 1000000007;
ll binom[4003][4003];
ll F[4000];

ll dp[4004][4004];
ll g(int N, int c) {
  ll& x = dp[N][c];
  if(x != -1) return x;

  if(c == 1 || N == c) return 1;

  return x = (g(N-1, c-1) + (g(N-1, c)*c) % M) % M;
}

ll f(int v) {
  if(F[v] != -1) return F[v];
  ll ans = 0;

  for(int i = 1; i <= v; ++i) {
    ans += g(v, i);
    ans = ans % M;
  }

  return F[v] = ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  cin >> n;

  //compute binomial coefficients
  for(int i = 0; i <= n; ++i) {
    for(int j = 0; j <= i; ++j) {
      if(j == 0 || j == i) binom[i][j] = 1;
      else binom[i][j] = (binom[i-1][j] + binom[i-1][j-1]) % M;
    }

    F[i] = -1;
  }

  F[0] = 1;

  for(int i = 0; i <= n; ++i) for(int j = 0; j <= n; ++j) dp[i][j] = -1;

  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    ans += (binom[n][i] * f(n-i)) % M;
    ans = ans % M;
  }

  cout << ans << endl;
}

