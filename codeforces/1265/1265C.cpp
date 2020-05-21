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
  
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; ++i) cin >> A[i];

    if(n < 10) { cout << "0 0 0" << endl; continue; }

    vector<pair<int, int>> cnt;
    cnt.push_back({A[0], 1});
    for(int i = 1; i < n; ++i) {
      int l = cnt.size() - 1;
      if(A[i] == cnt[l].first) {
        cnt[l].second++;
      }
      else {
        cnt.push_back({A[i], 1});
      }
    }

    int g, s = 0, b = 0;
    g = cnt[0].second;

    int i = 1;
    while(s <= g && i < n) { s += cnt[i].second; ++i; }

    while((b <= g || g+s+b < n/2) && i < n) { if(g+s+b+cnt[i].second > n/2) break; b += cnt[i].second; ++i; }

    if(g+s+b > n/2) { cout << "0 0 0" << endl; continue; }
    cout << g << " " << s << " " << b << endl;
  }
}

