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
Just follow instructions type problem
*/


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while(t--) {
    string name; cin >> name;
    int date; cin >> date;
    string garbage; cin >> garbage;

    int birth; cin >> birth;
    cin >> garbage;
    
    int courses; cin >> courses;

    string s;
    if(date >= 2010 || birth >= 1991) s = "eligible";
    else {
      if(courses <= 40) s = "coach petitions";
      else s = "ineligible";
    }

    cout << name << " " << s << endl;
  }
}

