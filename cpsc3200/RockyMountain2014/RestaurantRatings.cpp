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

vector<vector<vector<ll>>> dp;
vector<int> r;
int n;

ll f(int j, int sum, int worse) {
  if(j == n || sum == 0) return 1;
  if(sum <= 0) return 0;

  ll& x = dp[j][sum][worse];
  if(x != -1) return x;

  ll ans = 0;
  if(worse) {
    for(int i = 0; i <= sum; ++i) {
      ans += f(j+1, sum-i, 1); 
    }
  }
  else {
    ans = f(j+1, sum-r[j], 0);
    for(int i = 0; i < r[j]; ++i) ans += f(j+1, sum-i, 1);
    for(int i = r[j]+1; i <= sum; ++i) ans += f(j+1, sum-1-i, 1);
  }

  return x = ans;
}

/*
dp approach
*/

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  while(cin >> n && n) {
    r.assign(n, 0);

    int s = 0;
    for(int& x : r) { cin >> x; s += x; }

    dp.assign(17, vector<vector<ll>>(35, vector<ll>(2, -1)));
    
    cout << f(0, s, 0) << endl;

  }
}

