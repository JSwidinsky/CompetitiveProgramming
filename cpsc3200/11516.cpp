//binary search on the answer

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

vector<int> H;
int n;

bool check(double test) {
  double dist = 0;
  int cnt = 0;
  for(int i = 0; i < H.size(); ++i) {
    if(dist > H[i]) continue;
    else { 
      dist = (H[i] + 2*test);
      ++cnt;
      if(cnt > n) return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int m; cin >> n >> m;
    H.assign(m, 0);
    for(int& x : H) cin >> x;

    sort(all(H));

    if(n >= m) { cout << "0.0" << endl; continue; }

    double l = 0, h = H[m-1], mid;
    while(h - l > 0.001) {
      mid = (h+l)/2;
      if(check(mid)) h = mid;
      else l = mid;
    }

    cout << fixed << setprecision(1) << h << endl;
  }

}

