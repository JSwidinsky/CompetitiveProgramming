#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define FOR(s, n) for(int i = s; i < n; ++i)

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

const int MAX = 2000000;
vector<int> prime, palindrome;
vector<int> V1, V2;

bool isPalindrome(int x) {
  int temp = x;
  int V[10];

  int m = 0;
  while(temp > 0) {
    V[m] = temp % 10;
    temp /= 10;
    ++m;
  }
  
  int n = m;
  for(int i = 0; i <= n/2; ++i) {
    if(V[i] != V[n-i-1]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  prime.assign(MAX, 1);
  palindrome.assign(MAX, 0);
  V1.assign(MAX, 0);
  V2.assign(MAX, 0);
  
  prime[0] = prime[1] = 0;
  for(int i = 2; i < MAX; ++i) {
    if(prime[i]) {
      for(int j = 2*i; j < MAX; j += i) {
        prime[j] = 0;
      }
    }
  }

  for(int i = 1; i < MAX; ++i) {
    if(isPalindrome(i)) { palindrome[i] = 1; }
  }
  
  for(int i = 1; i < MAX; ++i) {
    if(prime[i]) V1[i] = V1[i-1]+1;
    else V1[i] = V1[i-1];

    if(palindrome[i]) V2[i] = V2[i-1] + 1;
    else V2[i] = V2[i-1];
  }

  int p, q; cin >> p >> q;
   
  for(int n = MAX-1; n >= 0; --n) {
    if(q*V1[n] <= p*V2[n]) {
      cout << n << endl;
      return 0;
    }
  } 
}

