//burte force string matching

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

int k, e;
set<string> keywords;

string change(const string& s) {
  string ret;
  for(char c : s) {
    if(isalpha(c)) ret += tolower(c);
    else ret += ' ';
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int count = 1;
  while(cin >> k >> e) {
    keywords.clear();
    for(int i = 0; i < k; ++i) {
      string s; cin >> s;
      keywords.insert(s);
    }
    
    cin.ignore();

    vector<string> excuses;
    int m = 0;
    for(int i = 0; i < e; ++i) {
      string excuse;
      getline(cin, excuse);
      string temp = change(excuse);

      istringstream iss(temp);

      int n = 0;
      string word;
      while(iss >> word) {
        if(keywords.count(word)) ++n;
      }

      if(n > m) {
        m = n;
        excuses.clear();
        excuses.push_back(excuse);
      }
      else if(n == m) {
        excuses.push_back(excuse);
      }
    }

    cout << "Excuse Set #" << count++ << endl;
    for(string& s : excuses) {
      cout << s << endl;
    }
    cout << endl;
  }
}

