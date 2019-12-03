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

vector<vector<int>> G;

string toLower(const string& s) {
  string ret;
  for(char c: s) {
    ret += tolower(c);
  }

  return ret;
}

vector<bool> visited;
int length(int n) {
  if(visited[n]) return 0;

  visited[n] = true;

  int ans = 0;
  for(int& i : G[n]) {
    ans = max(ans, length(i));
  }

  return ans + 1;
} 


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int n; cin >> n;
  
  map<string, int> M;
  M["polycarp"] = 0;

  G.assign(400, {});
  visited.assign(400, false);

  int count = 1;
  for(int i = 0; i < n; ++i) {
    string s; cin >> s;
    s = toLower(s);
    int first;
    if(!M.count(s)) M[s] = first = count++;
    else first = M[s];

    cin >> s >> s;

    int second;
    s = toLower(s);
    if(!M.count(s)) M[s] = second = count++;
    else second = M[s];

    G[first].push_back(second);
    G[second].push_back(first);
  }
  cout << length(0) << endl; 


}

