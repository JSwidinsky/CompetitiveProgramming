//mst; build an mst containing all nodes that are good, and then connect the bad nodes to the mst to force them to be leaves

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

struct UF {
  int n; vector<int> A;
  UF (int n) : n(n), A(n) { iota(begin(A), end(A), 0); }
  int find (int a) { return a == A[a] ? a : A[a] = find(A[a]); }
  bool connected (int a, int b) { return find(a) == find(b); }
  void merge (int a, int b) { A[find(b)] = find(a); }
};

struct edgelist {
  int A, B, weight;
};

/*
Minimum spanning tree
we compute the minimum spanning tree first with all nodes that are not bad
then we connect the bad nodes to our minimum spanning tree as leaves
*/


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, p; cin >> n >> m >> p;
  
  vector<int> bad(n, 0);
  for(int i = 0; i < p; ++i) {
    int x; cin >> x;
    --x;
    bad[x] = 1;
  }

  vector<edgelist> V; 
  vector<vector<edgelist>> B(n);

  for(int i = 0; i < m; ++i) {
    int a, b, w; cin >> a >> b >> w;
    --a; --b;

    if(bad[a]) B[a].push_back({a, b, w});
    else if(bad[b]) B[b].push_back({b, a, w});
    else V.push_back({a, b, w});
  }

  sort(all(V), [](edgelist A, edgelist B) { return A.weight < B.weight; });
 
  UF uf(n);
  
  int ans = 0; 
  for(auto e : V) { 
    if(uf.connected(e.A, e.B)) continue;
    
    uf.merge(e.A, e.B);
    ans += e.weight;
  }
 
  //check all bad nodes and add them to our mst
  for(int i = 0; i < n; ++i) {
    if(bad[i]) { 
      sort(all(B[i]), [](edgelist A, edgelist B) { return A.weight < B.weight; });

      for(auto& e : B[i]) {
        if((!bad[e.B] || (n == 2 && p == 2)) && !uf.connected(e.A, e.B)) {
          ans += e.weight;
          uf.merge(e.A, e.B);
          break;
        }
      }
    }
  }

  set<int> cnt;
  for(int i = 0; i < n; ++i) {
    cnt.insert(uf.find(i));
  }
  
  if(cnt.size() == 1) cout << ans << endl;
  else cout << "impossible" << endl;
}

