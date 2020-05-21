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

typedef unsigned long long int ull;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int n, k; cin >> n >> k;

  string s; cin >> s;

  set<char> C;
  for(int i = 0; i < k; ++i) {
    char a; cin >> a;
    C.insert(a);
  }
  
  vector<ull> A(n, 0);

  if(C.count(s[0])) A[0] = 1;
  for(int i = 1; i < n; ++i) {
    if(C.count(s[i])) A[i] = A[i-1] + 1;
    else A[i] = 0;
  }

  ull ans = 0;
  for(int i = 1; i < n; ++i) {
    if(A[i] == 0) {
      ans += (A[i-1] * (A[i-1]+1))/2;
    }
  }

  if(A[n-1] != 0) ans += (A[n-1] * (A[n-1]+1))/2;
  cout << ans << endl;
}

