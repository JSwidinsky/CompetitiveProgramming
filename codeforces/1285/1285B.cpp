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

typedef long long ll;

ll vecsum(vector<ll>& v, int n, int &start, int &end)
{
  ll maxval = 0;
  ll max_end = 0;
  ll max_end_start, max_end_end;
  ll i;

  start = max_end_start = 0;
  end = max_end_end = -1;
  for (i = 0; i < n; i++) {
    if (v[i] + max_end >= 0) {
      max_end = v[i] + max_end;
      max_end_end = i;
    } else {
      max_end_start = i+1;
      max_end_end = -1;
      max_end = 0;
    }

    if (maxval < max_end) {
      start = max_end_start;
      end = max_end_end;
      maxval = max_end;
    } else if (maxval == max_end) {
      /* put whatever preferences we have for a tie */
      /* eg. longest subvector, and then the one that starts the earliest */
      if (max_end_end - max_end_start > end - start ||
          (max_end_end - max_end_start == end - start &&
           max_end_start < start)) {
        start = max_end_start;
        end = max_end_end;
        maxval = max_end;
      }
    }
  }
  return maxval;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<ll> A(n);
    for(int i = 0; i < n; ++i) cin >> A[i];
    
    ll y = 0;
    ll maxel = -(1ll<<40);
    ll minel = (1ll<<40);
    for(int i = 0; i < n; ++i) { y += A[i]; maxel = max(maxel, A[i]); minel = min(minel, A[i]); }

    int s, e;
    ll temp = A[0]; A[0] = 0;
    ll a = vecsum(A, n, s, e);

    A[0] = temp; temp = A[n-1]; A[n-1] = 0; 
    a = max(a, vecsum(A, n, s, e));

    if(y > a) cout << "YES" << endl;
    else cout << "NO" << endl; 
  }
}

