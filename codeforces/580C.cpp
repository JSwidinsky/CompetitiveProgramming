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
vector<bool> C;
vector<bool> visited;
int n, m;

int DFS(int a, int cats) {
  if(visited[a]) return 0;
  visited[a] = true;

  if(C[a]) ++cats;
  else cats = 0;

  if(cats > m) return 0;

  if(G[a].size() == 1 && a != 0) return 1;
  
  int ans = 0;
  for(auto& i : G[a]) {
    ans += DFS(i, cats);
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;

  G.assign(n, {});
  C.assign(n, false);
  visited.assign(n, false);

  for(int i = 0; i < n; ++i) { int c; cin >> c; C[i] = (c == 1 ? true : false); }

  for(int i = 0; i < n-1; ++i) {
    int x, y; cin >> x >> y;

    --x; --y;

    G[x].push_back(y);
    G[y].push_back(x);
  }

  cout << DFS(0, 0) << endl;
}

