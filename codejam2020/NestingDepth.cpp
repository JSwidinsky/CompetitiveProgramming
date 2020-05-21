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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;

  int c = 0;
  while(t--) {
    string s; cin >> s;
    int n = s.length();

    vector<int> A(s.length());
    for(int i = 0; i < n; ++i) {
      A[i] = (s[i]-'0'); 
    }

    int opened = 0;
    string ans;
    for(int i = 0; i < n; ++i) {
      if(A[i] - opened < 0) {
        int bnd = opened-A[i];
        for(int i = 0; i < bnd; ++i) { ans += ')'; --opened; }
      }
      else if(A[i] - opened > 0) {
        int bnd = A[i]-opened;
        for(int i = 0; i < bnd; ++i) { ans += '('; ++opened; }
      }

      ans += ((char)('0'+A[i]));
    }

    while(opened > 0) { ans += ')'; --opened; }

    cout << "Case #" << ++c << ": " << ans << endl;
  }
}

