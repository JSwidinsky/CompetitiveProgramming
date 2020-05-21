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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  ll c, n, m;
  cin >> c >> n >> m;

  vector<int> farms(n);
  for(int& x : farms) cin >> x;

  vector<pii> days(m);
  for(int i = 0; i < m; ++i) {
    int d; cin >> d;
    days[i] = {d, i};
  }

  sort(all(days));

  vector<int> D(n, 0);
  ull cnt = 0;

  vector<int> Ans(m);
  int day = 0; ull ans = n;
  for(int i = 0; i <= 50; ++i) {
    if(day < m && i == days[day].first) {
      Ans[days[day].second] = ans;
      ++day;
    }

    for(int j = 0; j < n; ++j) {
      if(farms[j]*2 > c && !D[j]) { ++cnt; D[j] = 1; }
      else if(farms[j]*2 <= c) farms[j] *= 2;
    }
    
    ans += cnt;
    cnt *= 2;
  }
  
  for(int i = 0; i < m; ++i) {
    cout << Ans[i] << endl;
  }
}

