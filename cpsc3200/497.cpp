//longest increasing subsequence

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

int asc_seq(vector<int>& A, int n, vector<int>& S) {
  vector<int> last(n+1), pos(n+1), pred(n);
  if (n == 0) return 0;
  int len = 1;                  last[1] = A[pos[1] = 0];
  for (int i = 1; i < n; i++) {
    int j = upper_bound(last.begin()+1, last.begin()+len+1, A[i]) -
      last.begin();      // use lower_bound for strict increasing subsequence
    pred[i] = (j-1 > 0) ? pos[j-1] : -1;
    last[j] = A[pos[j] = i];    len = max(len, j);
  }
  int start = pos[len];
  for (int i = len-1; i >= 0; i--) {  S[i] = A[start];  start = pred[start];  }
  return len;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int t; cin >> t;
  cin.ignore();
  string temp; getline(cin, temp);
  int c = 0;
  while(t--) {
    if(c) cout << endl;
    c = 1;

    string s;
    vector<int> A;
    while(getline(cin, s) && s.length() > 0) {
      A.push_back(stoi(s));
    }
    debug(A);

    vector<int> S(A.size());
    int ans = asc_seq(A, A.size(), S);

    cout << "Max hits: " << ans << endl;
    debug(S);
    for(int i = 0; i < ans; ++i) {
      cout  << S[i] << endl;
    }
  }
}

