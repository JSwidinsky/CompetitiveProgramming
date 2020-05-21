//place a queen at any spot and count how many combintations we can make
//backtracking and pruning


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

vector<string> S;
vector<bool> col;
vector<bool> ldiag, rdiag;

int n, c = 0;

void solve(int row) {
  if(row == n) { ++c; return; }
  for(int i = 0; i < n; ++i) {
    if(S[row][i] != '*' && col[i] && ldiag[row+i] && rdiag[row-i+(n-1)]) {
      col[i] = ldiag[row+i] = rdiag[row-i+(n-1)] = false;
      solve(row+1);
      col[i] = ldiag[row+i] = rdiag[row-i+(n-1)] = true;
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int cnt = 0;
  while(cin >> n && n) {
    //if(cnt) cout << endl;
    c = 0;
    S.assign(n, "");
    col.assign(n, true);
    ldiag.assign(2*n, true);
    rdiag.assign(2*n, true);

    for(string& s : S) cin >> s;

    solve(0);
    cout << "Case " << ++cnt << ": " << c << endl;

  }

}

