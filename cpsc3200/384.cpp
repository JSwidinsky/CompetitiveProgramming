//just implementation based grammar rules

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

bool slump(string s) {
  if(s[0] != 'D' && s[0] != 'E') return false;

  int pos = 1;
  while(pos < s.length() && s[pos] == 'F') ++pos;

  if(pos == s.length() || pos == 1) return false;

  if(s[pos] == 'G' && pos+1 == s.length()) return true;

  return slump(s.substr(pos));
}

bool slimp(string s) { 
  if(s[0] != 'A') return false;

  if(s.size() == 2) return s[1] == 'H';

  if(s[1] == 'B') {
    return slimp(s.substr(2, s.length()-3)) && s[s.length()-1] == 'C';   
  }
  else {
    return slump(s.substr(1, s.length()-2)) && s[s.length()-1] == 'C'; 
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cout << "SLURPYS OUTPUT" << endl;
  int t; cin >> t;
  while(t--) {
    string s; cin >> s;
    if(t==1) debug(s);  
    bool b = false;
    for(int i = 1; i < s.length(); ++i) {
      if(slimp(s.substr(0, i)) && slump(s.substr(i))) b = true;
    }

    cout << (b ? "YES" : "NO") << endl;
  }

  cout << "END OF OUTPUT" << endl;
}

