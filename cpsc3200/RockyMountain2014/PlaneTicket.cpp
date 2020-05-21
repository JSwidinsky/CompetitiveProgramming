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


int K[55];
pair<ll, ll> W[55][105];
ll dp[305][55];

int weeks;
int best;

//f(n, w) = max revenue on week w if n people need to buy tickets
ll f(ll n, ll w) {
  if(n <= 0 || w < 0) return 0;

  ll& x = dp[n][w];
  if(x != -1) return x;
  
  ll ans = 0;
  ll tempans = ans;
  for(int i = 0; i < K[w]; ++i) {
    ans = max(ans, f(n-W[w][i].second, w-1)+W[w][i].first*min(n, W[w][i].second));
    
    if(ans != tempans && w == weeks) {
      tempans = ans;
      best = W[w][i].first;
    }
  }

  return x = ans;
}

/*
dp
*/


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int n, w; cin >> n >> w;
  weeks = w;

  for(int i = w; i >= 0; --i) {
    cin >> K[i];
    for(int j = 0; j < K[i]; ++j) cin >> W[i][j].first;

    for(int j = 0; j < K[i]; ++j) cin >> W[i][j].second;
  }

  for(int i = 0; i < 305; ++i) {
    for(int j = 0; j < 55; ++j) {
      dp[i][j] = -1;
    }
  }

  sort(W[w], W[w]+K[w]);

  cout << f(n, w) << endl << best << endl;
}

