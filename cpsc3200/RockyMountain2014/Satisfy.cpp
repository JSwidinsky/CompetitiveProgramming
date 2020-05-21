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
brute force bit-set operations. 
Check all possible assignments of values to the variables, and if one satisfies the expressions, then the statement is satisfiable
*/

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    cin.ignore();

    vector<vector<pair<int,int>>> A(m);
    map<string, int> M;
    int c = 0;
    for(int i = 0; i < m; ++i) {
      string T; getline(cin, T);
      
      istringstream iss(T);
      string s;
      while(iss >> s) {
        if(s == "v") continue;
        
        string temp;
        pair<int, int> p;
        if(s[0] == '~') { p.second = 1; temp = s.substr(1); }
        else { p.second = 0; temp = s; }

        if(M.count(temp)) p.first = M[temp];
        else p.first = M[temp] = c++;

        A[i].push_back(p);
      }
    }
    
    int ans = 0;
    for(int i = 0; i < (1 << n); ++i) {
      int a = 1;
      for(int j = 0; j < m; ++j) {
        int expr = 0;
        for(auto& p : A[j]) {
          if(p.second) expr = expr | (((1 << p.first) & i) ? 0 : 1);
          else expr = expr | ((1 << p.first) & i);
        }

        a = a && expr;
      }

      ans = ans || a;
    }

    if(ans) cout << "satisfiable" << endl;
    else cout << "unsatisfiable" << endl;
  }
}

