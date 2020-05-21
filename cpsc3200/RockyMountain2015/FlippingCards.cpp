#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;

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

/*
In this problem, we want to find each strongly connected component
and then count the number of cycles in each of the components
If the number of cycles is < 2, then it is possible, else it is not
*/

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;

    UF uf(2*n);
    vector<int> cnt(2*n, 0);
    for(int i = 0; i < n; ++i) {
      int a, b; cin >> a >> b;
      --a; --b;
      if(uf.connected(a,b)) {
        cnt[uf.find(a)]++;
      }
      else {
        cnt[uf.find(a)] += cnt[uf.find(b)];
        uf.merge(a,b);
      }
    }

    bool b = true;
    for(int i = 0; i < 2*n; ++i) {
      b = b && (cnt[uf.find(i)] < 2);
    }

    cout << (b ? "possible" : "impossible") << endl;
  }
}

