//bfs

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

vector<vector<int>> G;
vector<int> C;
int n;

bool colour(int node, int c) {
  int& x = C[node];
  if(x != -1) return c == x;

  x = c;
  
  bool b = true;
  for(int adj : G[node]) {
    b = b & colour(adj, !c);
  }

  return b;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  while(cin >> n && n) {
    G.assign(n, {});
    C.assign(n, -1);
    int e; cin >> e;
    for(int i = 0; i < e; ++i) { 
      int a, b; cin >> a >> b;

      G[a].push_back(b);
      G[b].push_back(a);
    }

    if(colour(0, 0)) cout << "BICOLORABLE." << endl;
    else cout << "NOT BICOLORABLE." << endl;
  }
}

