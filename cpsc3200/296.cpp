//exhaustive search

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

vector<pair<int, pair<int, int>>> V;
vector<int> A(4);
vector<int> B(4);

void split(int a, vector<int>& T) {
  for(int i = 3; i >= 0; --i) {
    T[i] = a % 10;
    a /= 10;
  }
}



bool check(int g) {
  split(g, A);

  for(auto& p : V) {
    int guess = p.first;
    int good = p.second.first, bad = p.second.second;
    split(guess, B);

    int numgood = 0;
    vector<bool> matched(4, false);
    vector<bool> used(4, false);
    for(int i = 0; i < 4; ++i) {
      if(A[i] == B[i]) { 
        ++numgood;
        used[i] = true;
        matched[i] = true;

      }
    }

    if(numgood != good) return false;

    int numbad = 0;
    for(int i = 0; i < 4; ++i){
      if(matched[i]) continue;
      for(int j = 0; j < 4; ++j) {
        if(i == j && A[i] == B[j]) continue;

        if(A[i] == B[j] && !used[j]) {
          used[j] = true;
          numbad++;
          break;
        }
      }
    }

    if(numbad != bad) return false;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n; 
    V.assign(n, {});

    if(n == 0) { cout << "indeterminate" << endl; continue; }

    for(int i = 0; i < n; ++i) {
      int a, b, c; char bad;
      cin >> a >> b >> bad >> c;
      V[i] = {a, {b, c}};
    }
    
    int ans = 0;
    int k;
    for(int i = 0; i <= 9999; ++i) {
      if(check(i)) { ++ans; k = i; }
    }

    if(!ans) { cout << "impossible" << endl; }
    else if(ans == 1) { cout << setfill('0') << setw(4) << k << endl; }
    else { cout << "indeterminate" << endl; }
  }

}

