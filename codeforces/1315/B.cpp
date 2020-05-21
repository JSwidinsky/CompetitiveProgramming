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
    int a, b, p; cin >> a >> b >> p;

    string s; cin >> s;

    int i = s.length() - 1;
    while(i >= 0 && s[i] == s[s.length()-1]) --i;
    
    ++i;
    int ans;
    if(i == 0) {
      if(s[i] == 'A') {
        if(a <= p) ans = 1;
        else ans = s.length();
      }
      else {
        if(b <= p) ans = 1;
        else ans = s.length();
      }
    }
    else {
      int cost;
      if(s[i] == 'B') cost = b;
      else cost = a;

      int best = i;

      int j = --i;
      while(i >= 0 && cost <= p) {
        
        while(i >= 0 && s[i] == s[j]) --i;

        ++i;
        if(s[i] == 'A') cost += a;
        else cost += b;

        if(cost <= p) best = i;

        j = --i;
      }

      ans = best+1;
    }
    cout << ans << endl;
  }
}

