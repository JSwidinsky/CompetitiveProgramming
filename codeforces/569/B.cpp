#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define FOR(s, n) for(int i = s; i < n; ++i)

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  
  vector<int> A(n), seen(100005, 0);
  for(int& x : A) { cin >> x; seen[x] = 1; }

  int ptr = 1;
  set<int> S;
  for(int i = 0; i < n; ++i) {
    if((!seen[A[i]] || !S.count(A[i])) && A[i] <= n) { cout << A[i] << " "; seen[A[i]] = 1; S.insert(A[i]); }
    else {
      while(seen[ptr] && ptr <= n) ++ptr; 
      cout << ptr << " ";
      seen[ptr] = 1;
      S.insert(ptr);
    }
  }
  cout << endl;

}

