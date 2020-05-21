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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> A(m);
    
    for(int& x : A) { cin >> x; --x; }

    vector<int> cnt(n, 0);

    for(int i : A) {
      ++cnt[i];
    }
    cnt[n-1] = 1;

    vector<int> ans(400, 0);

    long long int c = 0;
    for(int i = n-1; i >= 0; --i) {
      c += cnt[i];
      ans[s[i]] += c;
    }

    for(char i = 'a'; i <= 'z'; ++i) {
      cout << ans[i] << " ";
    }
    cout << endl;

  }

}

