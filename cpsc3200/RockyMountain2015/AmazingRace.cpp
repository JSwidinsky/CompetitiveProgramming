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

#define END n+1
#define START n

int n, T;
int G[23][23];
int points[21], times[21], deadline[21];
int totPoints[1<<20];
int dp[1<<20][20];

//compute points computes the total number of points that one could get if they do all 
//the events listed in the subset/mask variable
int computePoints(int subset) {
  int& x = totPoints[subset];
  if(x != -1) return x;

  for(int i = 0; i < n; ++i) {
    if(subset & (1<<(n-1-i))) x = points[i] + computePoints(subset - (1<<(n-1-i))); 
  }

  return x;
}


//f computes minimum time to do all events in mask and end at node labeled end
int f(int mask, int end) {
  int& x = dp[mask][end];
  
  if(x != -1) return x;
  
  if(mask == (1<<(n-1-end))) {
    int startTime = G[START][end] + times[end];
    return x = (startTime > deadline[end] ? T+1 : startTime); 
  }

  int ans = T+1;
  for(int i = 0; i < n; ++i) {
    if((mask & (1<<(n-1-i))) && i != end) {
      int newAns = f(mask-(1<<(n-1-end)), i) + G[i][end] + times[end];
      if(newAns <= deadline[end] || deadline[end] == -1) ans = min(ans, newAns);
    }
  }

  return x = ans;
}

/*
Dynamic programming
Compute the subset that gives maximum point value obeying constraints given in problem statement
*/

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> T;

  for(int i = 0; i < n; ++i) { cin >> points[i] >> times[i] >> deadline[i];
    if(deadline[i] == -1) deadline[i] = 1<<25;
  }
  
  for(int i = 0; i < n+2; ++i) 
    for(int j = 0; j < n+2; ++j)
      cin >> G[i][j];

  totPoints[0] = 0;
  for(int i = 1; i < (1<<n); ++i) totPoints[i] = -1;
  for(int i = 0; i < (1<<n); ++i) computePoints(i);
  
  for(int i = 0; i < (1<<n); ++i) 
    for(int j = 0; j < n; ++j)
      dp[i][j] = -1;

  
  int ans = 0, bestMask = 0;
  for(int i = 0; i < (1<<n); ++i) {
    for(int j = 0; j < n; ++j) {
      if(i & (1<<(n-1-j))) {
        int t = f(i,j) + G[j][END];
        if(t > T) continue;

        if(totPoints[i] > ans || (totPoints[i] == ans && i > bestMask)) {
          ans = totPoints[i];
          bestMask = i;
        }
      }
    }
  }

  //for(int i = 0; i < (1<<n); ++i) for(int j = 0; j < n; ++j) cout << i << " " << j << " " << dp[i][j]+G[j][END] << " " << totPoints[i] << endl;

  cout << ans << endl;
  for(int i = 0; i < n; ++i) {
    if(bestMask & (1<<(n-1-i))) cout << i+1 << " ";
  }

  cout << endl;
}

