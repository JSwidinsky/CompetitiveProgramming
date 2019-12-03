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

int n;

int G[1005][1005];

vector<pair<int, int>> cost;
vector<pair<int, int>> costCopy;


int main() {
  int m; cin >> n >> m;
  
  cost.assign(n, {});
  for(int i = 0; i < n; ++i) { int a; cin >> a; cost[i] = {a, i}; }

  for(int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;

    --a; --b;

    G[a][b] = 1;
    G[b][a] = 1;
  }

  costCopy = cost;

  sort(all(cost), [](auto a, auto b) -> bool {return a.first > b.first; });


  
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    int c = 0, node = cost[i].second;
    for(int j = 0; j < n; ++j) {
      if(G[node][j] == 1) { c += costCopy[j].first; G[node][j] = G[j][node] = 0; }
    }
    ans += c;
  }

  cout << ans << endl;
}
