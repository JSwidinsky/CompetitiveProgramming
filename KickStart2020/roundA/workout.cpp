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

int n, k;
vector<int> A;

bool check(int g) { 
  int placed = 0;
  for(int i = 0; i < n-1; ++i) {
    int pl = A[i];
    while(A[i+1] - pl > g) { 
      ++placed;

      if(placed > k) return false;
      pl += g;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  int c = 0;
  while(t--) {
    cin >> n >> k;

    A.assign(n, 0);
    for(int& x : A) cin >> x;
    
    int up = 0;
    for(int i = 0; i < n-1; ++i) { 
      up = max(up, A[i+1]-A[i]);
    }


    int low = 1;
    while(up - low > 1) {
      int mid = (up + low)/2;
      if(check(mid)) up = mid;
      else low = mid;
    }
    
    if(low == 1) { if(check(1)) up = 1; }
    cout << "Case #" << ++c << ": " << up << endl;
  }
}

