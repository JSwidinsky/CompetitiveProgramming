//just check each m to see if that value works for the problem. also use dp to memoize answers

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

int k;

bool check(int m) {
  int bad = k;
  int next = 0;
  while(bad > 0) {
    next = (next + m - 1) % (k + bad);
    if(next < k) return false;

    --bad;
  }

  return true;
}

int dp[15];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  while(cin >> k && k != 0) {
    int& x = dp[k];
    if(x != 0) { cout << x << endl; continue; }

    int m = k+1;
    while(!check(m)) ++m;
    x = m;
    cout << m << endl;
  }
}

