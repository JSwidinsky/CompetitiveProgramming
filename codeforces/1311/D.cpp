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
    int a, b, c; cin >> a >> b >> c;

    int A, B, C;
    int ans = (1 << 30);
    for(int i = 1; i <= 2*a; ++i) {
      for(int j = i; j <= 2*b; j += i) {
        int nans = abs(a - i) + abs(b - j);
        int C1 = (c / j)*j, C2 = (c / j)*j + j;
      
        int best;
        if(abs(C1 - c) < abs(C2 - c)) best = C1;
        else best = C2;

        nans += abs(best - c);
        
        if(nans < ans) {
          ans = nans;
          A = i;
          B = j;
          C = best;
        }
      }
    }

    cout << ans << endl;
    cout << A << " " << B << " " << C << endl;
  }
}

