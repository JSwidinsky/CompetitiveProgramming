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
    string a; cin >> a;

    string s(n, '0'), t(n, '0');
    bool b = false;
    for(int i = 0; i < n; ++i) {
      if(a[i] == '0') {
        s[i] = t[i] = '0';
      }
      else if(a[i] == '1') {
        if(b) {
          s[i] = '0';
          t[i] = '1';
        }
        else {
          s[i] = '1';
          t[i] = '0';
          b = true;
        }
      }
      else {
        if(b) {
          s[i] = '0';
          t[i] = '2';
        }
        else {
          s[i] = t[i] = '1';
        }
      }
    }

    cout << s << endl << t << endl;
  }
}

