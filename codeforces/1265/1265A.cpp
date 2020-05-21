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
    string s; cin >> s;
    
    int n = s.length();

    s += 'p';
    s = 'p' + s;
    bool b = true;
    for(int i = 1; i <= n; ++i) {
      if(s[i] == s[i+1] && s[i] != '?') { b = false; break; }

      if(s[i] == '?') {
        if(s[i-1] == 'a') {
          if(s[i+1] != 'b') s[i] = 'b';
          else if(s[i+1] != 'c') s[i] = 'c';
        }
        else if(s[i-1] == 'b') {
          if(s[i+1] != 'a') s[i] = 'a';
          else if(s[i+1] != 'c') s[i] = 'c';
        }
        else {
          if(s[i+1] != 'a') s[i] = 'a';
          else if(s[i+1] != 'b') s[i] = 'b';
        }
      }
    }

    if(b) { for(int i = 1; i <= n; ++i) cout << s[i]; cout << endl; }
    else cout << -1 << endl;

  }
}

