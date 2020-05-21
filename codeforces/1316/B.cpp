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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    
    string s; cin >> s;

    string A = s;
    int ans = 1;

    for(int k = 2; k <= n; ++k) {
      string T;
      for(int i = k-1; i < n; ++i) T += s[i];

      if((n-k+1) % 2 == 0 ) {
        for(int i = 0; i < k-1; ++i) T += s[i];
      }
      else {
        for(int i = k-2; i >= 0; --i) T += s[i];
      }

      if(T < A) {
        A = T;
        ans = k;
      }
    }

    cout << A << endl << ans << endl;
  }

}

