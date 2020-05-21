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

typedef pair<int, pair<int, int>> piii;
typedef pair<int, int> pii;

//G[i][j] is the ith city at fuel level j
vector<piii> G[1005][105];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int n, m; cin >> n >> m;
  
  vector<int> price(n);
  for(int& x : price) cin >> x;

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < 100; ++j) {
      G[i][j].push_back({price[i], {i, j+1}});
    }
  }

  for(int k = 0; k < m; ++k) {
    int A[2]; int d; cin >> A[0] >> A[1] >> d;

    for(int i = 0; i < 2; ++i) {
      for(int j = d; j <= 100; ++j) {
        G[A[i]][j].push_back({0, {A[(i+1)%2], j-d}});
      }
    }
  }

  int t; cin >> t;
  while(t--) {
    int c, s, e; cin >> c >> s >> e;
    
    priority_queue<piii, vector<piii>, greater<piii>> Q;
    Q.push({0, {s, 0}});

    vector<vector<int>> visited(1005, vector<int>(105, 0));

    int ans = -1;
    while(!Q.empty()) {
      auto p = Q.top(); Q.pop();

      int city = p.second.first, fuel = p.second.second;

      if(visited[city][fuel] || fuel > c) continue;
      visited[city][fuel] = 1;

      if(city == e) { ans = p.first; break; }

      for(auto& adj : G[city][fuel]) {
        Q.push({p.first + adj.first, adj.second});
      }
    }

    if(ans != -1) cout << ans << endl;
    else cout << "impossible" << endl;
  }

















}

