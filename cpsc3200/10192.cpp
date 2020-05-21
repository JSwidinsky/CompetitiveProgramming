//dp longest common subsequence

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

string s, t;
vector<vector<int>> dp;

int f(int i, int j) {
  if(i == 0 || j == 0) return 0;

  int& x = dp[i][j];
  if(x != -1) return x;

  if(s[i-1] == t[j-1]) return x = f(i-1, j-1) + 1;
  else return x = max(f(i-1,j), f(i,j-1));
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int c = 0;  
  while(getline(cin, s) && s != "#" && getline(cin, t)) {
    dp.assign(s.length()+6, vector<int>(t.length()+6, -1));
    cout << "Case #" << ++c << ": you can visit at most " << f(s.length(), t.length()) << " cities." << endl;
  }
}

