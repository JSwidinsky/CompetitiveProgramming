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

vector<int> A, B;

vector<bool> visited;
vector<int> ncolour;

int colour(int n, int c) {
  if(visited[n]) {
    return c == ncolour[n];
  }

  ncolour[n] = c;
  visited[n] = true;

  if(c) A.push_back(n);
  else B.push_back(n);

  int ret = 1;
  for(int& adj : G[n]) {
    ret = ret && colour(adj, !c);
  }
  
  return ret;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  

  int n, m; cin >> n >> m;
  
  G.assign(n, {});

  visited.assign(n, false);
  ncolour.assign(n, -1);
  for(int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;

    a--; b--;
    
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for(int i = 0; i < n; ++i) {
    if(!visited[i] && !colour(i, 0)) { cout << -1 << endl; return 0; }
  }

  cout << A.size() << endl;
  for(auto& a : A) cout << a+1 << " ";
  cout << endl << B.size() << endl;
  for(auto& b : B) cout << b+1 << " ";
  cout << endl;
}

