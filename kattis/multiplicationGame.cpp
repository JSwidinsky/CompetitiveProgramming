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
    long long int n; cin >> n;
    string p1; cin >> p1;
    string p2;
    if(p1 == "Alice") p2 = "Bob";
    else p2 = "Alice";
  
    vector<int> A(2, 0);
    int a = 0;

    int x = n;
    for(long long int i = 2; i*i <= n; ++i) {
      bool b = false;
      while(x % i == 0) {
        A[a]++;
        x /= i;
        b = true;
      }

      if(b) a++;

      if(a >= 3) break;
    }

    if(x != 1) {
      if(a <= 1) A[a] = 1;
      ++a;
    }

    if(a >= 3) cout << "tie" << endl;
    else if(a == 2) {
      int diff = abs(A[0] - A[1]);
      if(diff >= 2) cout << "tie" << endl;
      else if(diff == 1) cout << p1 << endl;
      else cout << p2 << endl;
    }
    else {
      if(A[0] % 2 == 0) cout << p2 << endl;
      else cout << p1 << endl;
    }
  }
}

