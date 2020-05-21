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
  int n; cin >> n;
  vector<string> S(n);
  for(string& s : S) cin >> s;
  
  pair<int, int> pos;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(S[i][j] == 'K') {
        pos = {i, j};
        goto done;
      }
    }
  }

  done:

  set<pair<int, int>> seen;
  queue<pair<int, pair<int, int>>> Q;
  Q.push({0, pos});
  while(!Q.empty()) {
    auto p = Q.front(); Q.pop();
    int x = p.second.first, y = p.second.second, cost = p.first;
     
    if(x == 0 && y == 0) { cout << cost << endl; return 0; }

    if(S[x][y] == '#') continue;

    if(seen.count({x, y})) continue;

    seen.insert({x, y});
    
    for(int r : {-2, 2}) {
      for(int s : {-1, 1}) {
        if((x + r < n && x + r >= 0) && (y + s < n && y + s >= 0)) {
          Q.push({cost+1, {x+r, y+s}});
        }
      }
    }

    
    for(int r : {-1, 1}) {
      for(int s : {-2, 2}) {
        if(x + r < n && x + r >= 0 && y + s < n && y + s >= 0) {
          Q.push({cost+1, {x+r, y+s}});
        }
      }
    }
  }

  cout << -1 << endl;
}

