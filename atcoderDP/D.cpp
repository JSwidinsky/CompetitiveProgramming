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

int n, w;
ll V[104], W[104];
ll dp[104][100004];

//f(i,j) gives max value of items from i to n when we have wght remaining in our knapsack
ll f(int i, int wght) {
  if(i == n || wght == 0) return 0;
  
  ll& x = dp[i][wght];
  if(x != -1) return x;
  
  x = f(i+1, wght);
  if(wght - W[i] >= 0) x = max(x, V[i] + f(i+1, wght - W[i]));

  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> w;
  for(int i = 0; i < n; ++i) cin >> W[i] >> V[i];

  for(int i = 0; i <= n; ++i) for(int j = 0; j <= w; ++j) dp[i][j] = -1;

  cout << f(0, w) << endl;
}

