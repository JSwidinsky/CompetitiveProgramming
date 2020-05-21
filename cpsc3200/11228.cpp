//minimum spanning tree

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

typedef long long ll;
typedef pair<ll, ll> pii;

struct Edge { ll w, a, b; Edge(ll W, ll A, ll B) : w(W), a(A), b(B) {}};

struct UF {
  int n; vector<int> A;
  UF (int n) : n(n), A(n) { iota(begin(A), end(A), 0); }
  int find (int a) { return a == A[a] ? a : A[a] = find(A[a]); }
  bool connected (int a, int b) { return find(a) == find(b); }
  void merge (int a, int b) { A[find(b)] = find(a); }
};

vector<Edge> G;
int n;
ll r;

pair<long double, long double> kruskal() {
  sort(G.begin(), G.end(), [] (Edge& a, Edge& b) { return a.w < b.w; });

  long double a = 0, b = 0;
  UF u(n);

  for(int i = 0; i < G.size(); ++i) {
    if(u.find(G[i].a) != u.find(G[i].b)) {
      u.merge(G[i].a, G[i].b);
      
      if(G[i].w <= r) a += sqrt(G[i].w);
      else b += sqrt(G[i].w);
    }
  }

  return {a, b};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int c = 1;
  int t; cin >> t;
  while(t--) {
   cin >> n >> r;
   r *= r;
   UF uf(n);
   vector<pii> A(n);
   for(int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    A[i] = {x, y};
   }

   G.clear();

   for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      pii p1 = A[i], p2 = A[j];
      ll dist = (p1.fst - p2.fst)*(p1.fst - p2.fst) + (p1.snd - p2.snd)*(p1.snd - p2.snd);
      if(r >= dist) uf.merge(i, j);

      G.push_back(Edge(dist, i, j));
    }
   }

   pair<long double, long double> p = kruskal();

   set<int> S;
   for(int i = 0; i < n; ++i) {
    S.insert(uf.find(i));
   }

   cout << "Case #" << c++ << ": " << S.size() << " " << round(p.fst) << " " << round(p.snd) << endl;
  }
}

