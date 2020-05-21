//union find to keep track of which computers are connected in a network

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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int t; cin >> t;
  
  while(t--) {
    string s;
    int n; cin >> n;
    cin.ignore();
    UF uf(n);
    int succ = 0, unsucc = 0;
    while(getline(cin, s) && !s.empty()) {
      istringstream iss(s);
      char c; int a, b;
      iss >> c >> a >> b;
      a--; b--;
      if(c == 'c') {
        uf.merge(a, b);
      }
      else {
        if(uf.find(a) == uf.find(b)) ++succ;
        else ++unsucc;
      }
    }

    cout << succ << "," << unsucc;
    if(t != 0) cout << endl << endl;
    else cout << endl;
  }
}

