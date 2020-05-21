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
  while(t--) {
    int n; cin >> n;

    vector<int> matched(n, 0), picked(n, 0);
    int m = 0;
    for(int i = 0; i < n; ++i) {
      int num; cin >> num;
      for(int j = 0; j < num; ++j) {
        int a; cin >> a; --a;
        if(!matched[i] && !picked[a]) {
          ++m;
          matched[i] = true;
          picked[a] = true;
        }
      }
    }
    
    if(m == n) cout << "OPTIMAL" << endl;
    else {
      int i, j;
      for(i = 0; i < n; ++i) {
        if(!matched[i]) break;
      }

      for(j = 0; j < n; ++j) {
        if(!picked[j]) break;
      }

      cout << "IMPROVE" << endl << i+1 << " " << j+1 << endl;
    }

  }
}

