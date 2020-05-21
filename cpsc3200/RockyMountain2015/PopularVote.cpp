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

/*
Straight forward implementation problem
*/

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<pair<int, int>> V(n);

    for(int i = 0; i < n; ++i) {
      int a; cin >> a;
      V[i] = {a, i+1};
    }

    sort(all(V));

    int max = V[n-1].first;
    if(V[n-2].first == max) { cout << "no winner" << endl; continue; }
    
    int total = 0;
    for(int i = 0; i < n; ++i) total += V[i].first;

    if((double)(max)/total > 0.5) cout << "majority winner " << V[n-1].second << endl;
    else cout << "minority winner " << V[n-1].second << endl;
  }
}

