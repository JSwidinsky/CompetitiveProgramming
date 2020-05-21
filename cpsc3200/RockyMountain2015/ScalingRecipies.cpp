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

typedef long double ld;

/*
Just do it implementation problem
Basically just follow the problem statement and do what they tell you to do
*/


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;

  cout << fixed << setprecision(1) << endl;

  int c = 0;
  while(t--) {
    int r, p, d; cin >> r >> p >> d;

    vector<pair<string, pair<ld, ld>>> V(r);

    int ind;
    for(int i = 0; i < r; ++i) {
      string s; ld A, B;
      cin >> s >> A >> B;

      V[i] = {s, {A, B}};
      if(B == 100.0) ind = i;
    }

    ld scale = (ld)(d) / p;

    V[ind].second.first *= scale;

    for(int i = 0; i < r; ++i) {
      V[i].second.first = (V[i].second.second / 100.0) * V[ind].second.first;
    }

    cout << "Recipe # " << ++c << endl;
    for(auto& p : V) {
      cout << p.first << " " << p.second.first << endl;
    }

    cout << string(40, '-') << endl;
  }
}

