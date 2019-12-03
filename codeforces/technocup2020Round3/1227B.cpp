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

vector<bool> used;
int mmin;

void f() {
  while(used[mmin]) ++mmin;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; ++i) cin >> A[i];

    used.assign(n+5, false);
    vector<int> ans(n);
    ans[0] = A[0];
  
    used[A[0]] = true;

    bool b = false;
    mmin = 1;
    for(int i = 1; i < n; ++i) {
      f();
      if((used[A[i]] && mmin > A[i]) || (A[i] == A[i-1] && mmin > A[i])) { b = true; break; }

      if(A[i] == A[i-1]) { ans[i] = mmin; used[mmin] = true; }
      else { ans[i] = A[i]; used[A[i]] = true; }
    }

    if(b) { cout << -1 << endl; continue; }
    for(int& i : ans) cout << i << " ";
    cout << endl;

  }
} 

