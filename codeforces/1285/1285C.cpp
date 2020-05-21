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
  ll x; cin >> x;
  ll temp = x;

  vector<ll> factors;
  for(int i = 2; i*i <= temp; ++i) { 
    ll a = 1; bool b = false;
    while(x % i == 0) { b = true; a *= i; x /= i; }
    if(b) factors.push_back(a);
  }

  int bm;
  pair<int, int> p = {1, temp};
  ll m;
  
  for(bm = 1; bm < (1 << factors.size()); ++bm) {
    ll a = 1;
    for(int i = 0; i < factors.size(); ++i) {
      if(bm & (1 << i)) a *= factors[i];
    }
    
    ll b = temp / a;
    if(max(a, b) < m) { m = max(a, b); p = {a, b}; }
  }

  cout << p.first << " " << p.second << endl;

}

