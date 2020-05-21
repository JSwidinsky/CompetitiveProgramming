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

int n, p, q, s;
vector<int> P, Q;

bool check(int d) {
  
  int placed = 0;
  vector<int> used(q, 0);

  for(int i = p-1; i >= 0; --i) {
    auto upp = lower_bound(all(P), P[i] + d), low = lower_bound(all(P), P[i] - d);

    while(upp != low) {
      if(*upp + P[i] <= s && !used[*upp]) { ++placed; used[*upp] = 1; break; }
      --upp;
    }
  }

  return placed == n;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  cin >> n >> p >> q >> s;

  P.assign(p, 0);
  Q.assign(q, 0);

  for(auto& x : P) cin >> x;
  for(auto& x : Q) cin >> x;

  sort(all(P), [](int a, int b) { return a > b; });
  sort(all(Q), [](int a, int b) { return a > b; });
  
  int l = 0, h = s;

  while(h - l > 1) {
    debug(l); debug(h);
    int mid = (h + l)/2;
    if(check(mid)) h = mid; 
    else l = mid;
  }

  cout << h << endl;
}

