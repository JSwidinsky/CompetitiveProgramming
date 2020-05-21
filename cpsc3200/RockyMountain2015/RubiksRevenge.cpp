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

void rotaterow(string s, int dist, queue<pair<string, int>>& Q) {
  for(int i = 0; i < 4; ++i) {
    string n = s;
    char temp = n[i*4+3];
    n[i*4+3] = n[i*4+2];
    n[i*4+2] = n[i*4+1];
    n[i*4+1] = n[i*4];
    n[i*4] = temp;
    Q.push({n, dist+1});

    n = s;
    temp = n[i*4];
    n[i*4] = n[i*4+1];
    n[i*4+1] = n[i*4+2];
    n[i*4+2] = n[i*4+3];
    n[i*4+3] = temp;
    Q.push({n, dist+1});
  }
}

void rotatecol(string s, int dist, queue<pair<string, int>>& Q) {
  for(int i = 0; i < 4; ++i) {
    string n = s;
    char temp = n[i];
    n[i] = n[i+4];
    n[i+4] = n[i+8];
    n[i+8] = n[i+12];
    n[i+12] = temp;
    Q.push({n, dist+1});

    n = s;
    temp = n[i+12];
    n[i+12] = n[i+8];
    n[i+8] = n[i+4];
    n[i+4] = n[i];
    n[i] = temp;
    Q.push({n, dist+1});
  }
}


/*
two-way breadth-first search with some implementation details
that are annoying
*/

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string start, end;
  for(int i = 0; i < 4; ++i) {
    string s; cin >> s;
    start += s;
  }

  end = "RRRRGGGGBBBBYYYY";
  if(start == end) {
    cout << 0 << endl;
    return 0;
  }

  map<string, int> discForward, discBackward;
  queue<pair<string, int>> Qforward, Qbackward;
  int forwardDist = 0, backwardDist = 0;

  Qforward.push({start, 0});
  Qbackward.push({end, 0}); 
  while(!Qbackward.empty() || !Qforward.empty()) {
    while(!Qbackward.empty()) {
      auto [next, dist] = Qbackward.front(); 
      if(backwardDist < dist) { ++backwardDist; break; }
      Qbackward.pop();

      if(discBackward.count(next)) continue;

      if(discForward.count(next)) {
        cout << discForward[next] + dist << endl;
        return 0;
      }

      discBackward[next] = dist;
    
      rotaterow(next, dist, Qbackward);
      rotatecol(next, dist, Qbackward);
    }
   
    while(!Qforward.empty()) {
      auto [next, dist] = Qforward.front(); 
      if(forwardDist < dist) { ++forwardDist; break; }
      Qforward.pop();
      
      if(discForward.count(next)) continue;
      if(discBackward.count(next)) {
        cout << discBackward[next] + dist << endl;
        return 0;
      }

      discForward[next] = dist;

      rotaterow(next, dist, Qforward);
      rotatecol(next, dist, Qforward);
    }
  }
  
  assert(false);
}

