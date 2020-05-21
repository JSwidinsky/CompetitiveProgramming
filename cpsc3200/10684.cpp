//vecsum

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

int vecsum(int v[], int n, int &start, int &end)
{
  int maxval = 0, max_end = 0, max_end_start, max_end_end;
  start = max_end_start = 0;       end = max_end_end = -1;
  for (int i = 0; i < n; i++) {
    if (v[i] + max_end >= 0) {  max_end = v[i] + max_end;    max_end_end = i;
    } else { max_end_start = i+1;    max_end_end = -1;    max_end = 0; }


    if (maxval < max_end) {
      start = max_end_start;   end = max_end_end;    maxval = max_end;
    } else if (maxval == max_end) {    }  /* tie-breaking here */
  }
  return maxval;
}

int A[10005];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int n;
  while(cin >> n && n) {
    for(int i = 0; i < n; ++i) cin >> A[i];
  
    int s = 0, e = 0;
    int val = vecsum(A, n, s, e);

    if(val > 0) cout << "The maximum winning streak is " << val << "." << endl;
    else cout << "Losing streak." << endl;
  }
}

