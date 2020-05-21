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

int n;
int dp[100005];
int A[100005];

//f(i) gives minimum cost to reach stone n starting from stone i
int f(int i) {
  if(i == n) return 0;
  
  int& x = dp[i];
  if(x != -1) return x;
  
  if(i + 2 > n) x = abs(A[i] - A[i+1]) + f(i+1);
  else x = min(abs(A[i] - A[i+1]) + f(i+1), abs(A[i] - A[i+2]) + f(i+2));
  
  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> A[i];
    dp[i] = -1;
  }

  cout << f(1) << endl;  
}

