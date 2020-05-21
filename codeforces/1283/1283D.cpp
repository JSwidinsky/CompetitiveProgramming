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
  int n, m; cin >> n >> m;
  
  vector<int> A(n);
  for(int& x : A) cin >> x;

  queue<pair<int, int>> q;
  set<int> seen;

  for(int x : A) {
    q.push({x - 1, x});
    q.push({x + 1, x});

    seen.insert(x);
  }

  int placed = 0;
  vector<int> ans(m); 
  long long dist = 0;
  while(placed < m) {
    auto p = q.front(); q.pop();
    int loc = p.first, tree = p.second;
    
    if(seen.count(loc)) continue;
    seen.insert(loc);
    
    dist += abs(loc - tree);
    ans[placed] = loc;
    ++placed;

    q.push({loc + 1, tree});
    q.push({loc - 1, tree});
  }

  cout << dist << endl;
  for(int& i : ans) cout << i << " ";
  cout << endl;


}

