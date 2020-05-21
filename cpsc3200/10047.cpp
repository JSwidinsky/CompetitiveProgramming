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

struct Node {
  int r, c, dir, col, dist;
};


int A[4][2] {
  { -1, 0 },
  { 0, 1 },
  { 1, 0 },
  { 0, -1 }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int n, m;
  int c = 0;
  while(cin >> n >> m && n) {
    if(c) cout << endl;

    vector<string> S(n);
    for(int i = 0; i < n; ++i) cin >> S[i];

    int N, M;
    for(int i = 0; i < n; ++i) 
      for(int j = 0; j < m; ++j) 
        if(S[i][j] == 'S') {
          N = i; M = j;
        }
    
    int visited[30][30][4][5];
    for(int i = 0; i < 30; ++i)
      for(int j = 0; j < 30; ++j)
        for(int k = 0; k < 4; ++k)
          for(int l = 0; l < 5; ++l)
            visited[i][j][k][l] = 0;


    queue<Node> Q;
    Q.push({N, M, 0, 0, 0});

    int ans = -1;
    bool b = false;
    while(!Q.empty()) {
      Node top = Q.front(); Q.pop();
      
      int i = top.r, j = top.c;
      
      if(visited[i][j][top.dir][top.col]) continue;
      visited[i][j][top.dir][top.col] = 1;
      
      if(i >= n || i < 0 || j >= m || j < 0 || S[i][j] == '#') continue;

      if(S[i][j] == 'T' && top.col == 0) {
        b = true;
        ans = top.dist;
        break;
      }

      Q.push({i, j, ((top.dir - 1) + 4) % 4, top.col, top.dist+1});
      Q.push({i, j, (top.dir + 1) % 4, top.col, top.dist+1});
      Q.push({i+A[top.dir][0], j+A[top.dir][1], top.dir, (top.col + 1) % 5, top.dist+1});
    }

    cout << "Case #" << ++c << endl;
    if(b) cout << "minimum time = " << ans << " sec" << endl;
    else cout << "destination not reachable" << endl;

  }
}

