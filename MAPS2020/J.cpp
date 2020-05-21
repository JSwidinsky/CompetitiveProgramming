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
typedef long double ld;

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
  
  int n; cin >> n;
  cout << fixed << setprecision(7) << endl;
  vector<int> A(n);
  for(int& x : A) cin >> x;

  ld curr = 0.0f;
  for(int i = 0; i < n; ++i) {
    curr += A[i] * pow(4.0f/5.0f, i);    
  }
  cout << 1/5.0f * curr << endl;

  ld avg = 0.0f;
  for(int i = 0; i < n; ++i) {
    ld a = 0.0f;
    int p = 0;
    for(int j = 0; j < n; ++j) {
      if(i != j) {
        a += A[j] * pow(4.0f/5.0f, p);
        ++p;
      }
    }
    avg += (1/5.0f * a);
  }

  cout << avg << endl;
}

