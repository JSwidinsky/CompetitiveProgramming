//use two priority queues to maintain ith smallest element


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


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int t; cin >> t;
  int cnt = 0;
  while(t--) {
    if(cnt) cout << endl;
    cnt = 1;
    int l, n; cin >> l >> n;

    vector<ll> A(l);
    for(int i = 0; i < l; ++i) cin >> A[i];
  
    //M is max; m is min
    priority_queue<ll, vector<ll>, greater<ll>> m;
    priority_queue<ll> M;

    int i = 1, Aptr = 1;
    M.push(A[0]);
    for(int j = 0; j < n; ++j) {
      ll u; cin >> u;
      while(Aptr < u) {
        if(A[Aptr] > M.top()) {
          m.push(A[Aptr]);
        }
        else {
          M.push(A[Aptr]);
        }

        ++Aptr;
      }
      
      while(M.size() != i) {
        if(M.size() < i) {
          M.push(m.top());
          m.pop();
        }
        else {
          m.push(M.top());
          M.pop();
        }
      }

      ++i;

      cout << M.top() << endl;
    }
  }

}

