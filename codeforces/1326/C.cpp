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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int n, k; cin >> n >> k;

  vector<int> A(n), pos;
  for(int i = 0; i < n; ++i) {
    cin >> A[i];

    if(A[i] <= n && A[i] > n-k) pos.push_back(i);
  }

  ll sum = 0;
  for(int i = n; i > n-k; --i) sum += i;

  ll ans = 1;
  for(int i = 0; i < k-1; ++i) {
    ans *= ((pos[i+1] - pos[i] - 1) + 1);
    ans %= 998244353;
  }

  cout << sum << " " << ans << endl;
}

