//simulate each press and increment an answer vector

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

map<char, set<int>> M = {
  {'c', {2, 3, 4, 7, 8, 9, 10} },
  {'d', {2, 3, 4, 7, 8, 9} },
  {'e', {2, 3, 4, 7, 8} },
  {'f', {2, 3, 4, 7} },
  {'g', {2, 3, 4} },
  {'a', {2, 3} },
  {'b', {2} },
  {'C', {3} },
  {'D', {1, 2, 3, 4, 7, 8, 9} },
  {'E', {1, 2, 3, 4, 7, 8} },
  {'F', {1, 2, 3, 4, 7} },
  {'G', {1, 2, 3, 4} },
  {'A', {1, 2, 3} },
  {'B', {1, 2} }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  cin.ignore();
  while(t--) {
    string s; getline(cin, s);
    vector<int> ans(11, 0); vector<bool> pressed(11, false);
    for(char c : s) {
      for(int i = 1; i <= 10; ++i) {
        if(M[c].count(i)) {
          if(!pressed[i]) {
            ans[i]++;
            pressed[i] = true;
          }
        }
        else {
          pressed[i] = false;
        }
      }

    }

    for(int i = 1; i <= 10; ++i) {
      if(i == 1) cout << ans[i];
      else cout << " " << ans[i];
    }
    cout << '\n';
  }
}

