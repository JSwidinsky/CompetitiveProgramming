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


/*  O(n) find strongly connected components in a digraph
 *  comp[i] = component containing vertex i.
 *  dag[i] = adjacency list of the i'th strongly connected component
 */
struct SCC {
  int n, c;
  vector<vector<int>> G, H;
  vector<int> ord, comp;
  vector<bool> V;
  SCC(int n) : n(n), G(n), H(n) { };
  void add_edge(int u, int v) {
    G[u].push_back(v);
    H[v].push_back(u);
  }
  void dfs1(int v) { 
    V[v] = true;
    for (auto& u : G[v])
      if (!V[u]) dfs1(u);
    ord.push_back(v);
  }
  void dfs2(int v) {
    comp[v] = c;
    for (auto& u : H[v])
      if (comp[u] == -1) dfs2(u);
  }
  vector<int> scc() {
    V.assign(n, 0);
    for (int i = 0; i < n; i++)
      if (!V[i]) dfs1(i);
    comp.assign(n, -1); c = 0;
    for (int i = 0; i < n; i++) {
      int v = ord[n-1-i];
      if (comp[v] == -1) dfs2(v), c++;
    }
    return comp;
  }
  vector<vector<int>> dag() {
    set<pair<int, int>> S;
    vector<vector<int>> dag(c);
    for (int a = 0; a < n; a++) {
      for (auto& b : G[a]) {
        if (comp[a] == comp[b]) continue;
        if (!S.count({comp[a], comp[b]})) {
          dag[comp[a]].push_back(comp[b]);
          S.insert({comp[a], comp[b]});
        }
      }
    }
    return dag;
  }
};


/*
The approach is to build a graph that is bipartite with the facility locations
on one side and the n people on the other. Then, we connect a person with a 
facility location if the cost equals 0. Then we count the number of components
that the n people belong to. If this <= k, then we print yes.

I originally used a dfs to count # of connected components, but got wrong answer
I thought it had to do with my dfs so I switched to SCC code to count components
Only later realized there was a special case where you add no edges to your graph
*/


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int m, n, k; cin >> m >> n >> k;

  SCC G(n+m);
  bool addedEdge = false;
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      int a; cin >> a;
      if(a == 0) {
        addedEdge = true;
        G.add_edge(i, j+m);
        G.add_edge(j+m, i);
      }
    }
  }

  if(!addedEdge) {
    cout << "no" << endl;
    return 0;
  }
  
  auto C = G.scc();
  debug(C);

  set<int> S;
  for(int i = m; i < m+n; ++i) S.insert(C[i]);

  cout << (S.size() <= k ? "yes" : "no") << endl;
}

