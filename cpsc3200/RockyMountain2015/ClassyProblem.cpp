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

enum Rank {t, l, m, u};

/*
This is really just a sorting problem
The lambda function f is what does the sorting
*/

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;

    map<string, vector<Rank>> M;
    vector<string> names;

    //get input
    for(int i = 0; i < n; ++i) {
      string s, t, bad; cin >> s >> t >> bad;
      string name = s.substr(0, s.length()-1);
      names.push_back(name);

      int tptr = 0;
      while(tptr < t.length()) {
        string temp;
        while(tptr < t.length() && t[tptr] != '-') {
          temp += t[tptr];
          ++tptr;
        }
        ++tptr;
        
        Rank r;
        if(temp == "upper") r = Rank::u;
        else if(temp == "middle") r = Rank::m;
        else r = Rank::l;

        M[name].push_back(r);
      }
    }


    //the sorting funtion
    auto f = [&] (string s, string t) {
      vector<Rank> A = M[s], B = M[t];
      
      reverse(all(A));
      reverse(all(B));

      for(int i = 0; i < max(A.size(), B.size()); ++i) {
        if(i >= A.size()) A.push_back(Rank::m);
        if(i >= B.size()) B.push_back(Rank::m);
      }
      
      for(int i = 0; i < A.size(); ++i) {
        if(A[i] != B[i]) return A[i] > B[i];
      }

      return s < t;
    };

    sort(all(names), f);

    for(auto& a : names) cout << a << endl;
    cout << string(30, '=') << endl;
  }
}

