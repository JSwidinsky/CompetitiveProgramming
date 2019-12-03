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
/*
struct UF {
  int n; vector<int> A;
  UF (int n) : n(n), A(n) { iota(begin(A), end(A), 0); }
  int find (int a) { return a == A[a] ? a : A[a] = find(A[a]); }
  bool connected (int a, int b) { return find(a) == find(b); }
  void merge (int a, int b) { A[find(b)] = find(a); }
};
*/


vector<vector<int>> G;
vector<bool> visited;

void bfs(int n) {
  queue<int> q;
  
  q.push(n);
  while(!q.empty()) {
    int top = q.front(); q.pop();

    if(visited[top]) continue;
    visited[top] = true;

    for(int& adj : G[top]) {
      q.push(adj);
    }
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
    
  int n; cin >> n;
  int cnt = 26;

  map<string, int> M;
  
  G.assign(40+n, {});
  visited.assign(40+n, {});
  for(int i = 0; i < n; ++i) {
    string s; cin >> s;

    M[s] = cnt;
    for(char& c : s) {
      int val = c - 'a';
      
      G[val].push_back(cnt);
      G[cnt].push_back(val);
    }
    cnt++;
  }

  int ans = 0;
  for(auto& p : M) {
    if(!visited[p.second]) {
      ++ans;
      bfs(p.second);
    }
  }
  
  cout << ans << endl;
}

