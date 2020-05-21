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

const int N = 100005;

int n;
int A[N], B[N], C[N];
int dp[N][2][2][2];

//f(i, a, b, c) gives maximum happiness starting at day i having done one of a, b, c activities last day
int f(int day, int a, int b, int c) {
  if(day == n) return 0;
  
  int& x = dp[day][a][b][c];
  if(x != -1) return x;

  if(a) x = A[day] + f(day+1, 0, 1, 1);
  if(b) x = max(x, B[day] + f(day+1, 1, 0, 1));
  if(c) x = max(x, C[day] + f(day+1, 1, 1, 0));

  return x;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> A[i] >> B[i] >> C[i];
  }

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < 2; ++j) {
      for(int k = 0; k < 2; ++k) {
        for(int l = 0; l < 2; ++l) {
          dp[i][j][k][l] = -1;
        }
      }
    }
  }

  cout << f(0, true, true, true) << endl;
}

