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

typedef pair<pair<int, int>, int> piii;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  int cnt = 0;
  while(t--) {
    int n; cin >> n;

    vector<piii> A(n);
    for(int i = 0; i < n; ++i) {
      int a, b; cin >> a >> b;
      A[i] = {{a, b}, i};
    }

    sort(all(A));

    int c = 0, j = 1;
    string ans(n, 't');
    ans[A[0].second] = 'C';
    ans[A[1].second] = 'J';
    bool b = true;

    for(int i = 2; i < n && b; ++i) {
      if(A[c].first.second <= A[i].first.first) {
        c = i;
        ans[A[i].second] = 'C';
      }
      else if (A[j].first.second <= A[i].first.first) {
        j = i;
        ans[A[i].second] = 'J';
      }
      else b = false;
    }

    cout << "Case #" << ++cnt << ": " << (b ? ans : "IMPOSSIBLE") << endl;
  }
}

