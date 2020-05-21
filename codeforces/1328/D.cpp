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
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> A(n);

    bool same = true;
    cin >> A[0];
    for(int i = 1; i < n; ++i) {
      cin >> A[i];
      if(A[i] != A[i-1]) same = false;
    }

    if(same) {
      cout << 1 << endl;
      for(int i = 0; i < n; ++i) {
        cout << 1 << " ";
      }
      cout << endl;
    }
    else {
      if(n % 2 == 0) {
        cout << 2 << endl;
        for(int i = 0; i < n; ++i) {
          if(i % 2 == 0) cout << 1 << " ";
          else cout << 2 << " ";
        }
        cout << endl;
      }
      else {
        vector<int> R;
        R.push_back(A[0]);

        for(int i = 1; i < n; ++i) {
          if(i == n-1 && A[i] == A[0]) continue;
          if(A[i] != A[i-1]) R.push_back(A[i]);
        }

        if(R.size() % 2 == 0) {
          cout << 2 << endl;
          cout << 1 << " ";
          int last = 1;
          for(int i = 1; i < n; ++i) {
            if(A[i] != A[i-1]) last = (last % 2) + 1;
            cout << last << " ";
          }
          cout << endl;
        }
        else {
          cout << 3 << endl;
          for(int i = 0; i < n-1; ++i) {
            if(i % 2 == 0) cout << 1 << " ";
            else cout << 2 << " ";
          }
          cout << 3 << endl;
        }
      }
    }
  }
}

