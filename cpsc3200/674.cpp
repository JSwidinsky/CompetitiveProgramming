//bottom-up dp

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

vector<int> dp;
int coins[] = {1, 5, 10, 25, 50};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  dp.assign(8000, 0);

  dp[0] = 1;
  for(int coin : coins) {
    for(int i = 0; i < 7500; ++i) {
      if(i - coin >= 0) dp[i] += dp[i-coin];
    }
  }

  while(cin >> n) {
    cout << dp[n] << endl;
  }
}

