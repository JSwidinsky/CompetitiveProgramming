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

vector<int> A;
int b;

void comp(int l, int r) {
  for(int i = 0; i < l; ++i) {
    if(A[i] == 1) A[i] = 0;
    else A[i] = 1;
  }

  for(int i = r+1; i < b; ++i) {
    if(A[i] == 1) A[i] = 0;
    else A[i] = 1;
  }
}

void flip(int l, int r) {
  for(int i = 0; i < l; ++i) {
    swap(A[i], A[b-i-1]);
  }
}

void compflip(int l, int r) {
  comp(l, r);
  flip(l, r);
}

bool normal(const vector<int>& left, const vector<int>& right, int diff) {
  bool ret = true;
  
  for(int i = 0; i < 2; ++i) {
    ret = ret && (left[i] == A[diff+i]) && (right[(i+1)%2] == A[(b-1)-diff-i]);
  }

  return ret;
}

bool isComp(vector<int> left, vector<int> right, int diff) {
  for(int i = 0; i < 2; ++i) {
    if(left[i] == 1) left[i] = 0;
    else left[i] = 1;

    if(right[i] == 1) right[i] = 0;
    else right[i] = 1;
  
  }

  return normal(left, right, diff);
}

bool isFlipped(vector<int> left, vector<int> right, int diff) {
  bool ret = true;

  for(int i = 0; i < 2; ++i) {
    ret = ret && (A[diff+i] == right[(i+1)%2]) && (left[i] == A[(b-1)-diff-i]);
  }

  return ret;
}
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int t; cin >> t >> b;
  while(t--) {
    A.assign(b, 0);

    for(int i = 0; i < 5; ++i) {
      cout << i+1 << endl;
      
      cin >> A[i];

      cout << b-i << endl;
      cin >> A[b-i-1];
    }

    int n = b-10;
    
    //l and r are 0-based
    int l = 5, r = b-6;
    while(n > 0) {
      vector<int> left(2), right(2);
      int diff = 0;
      for(int i = 0; i < l; ++i) {
        if(A[i] != A[r+i+1]) { diff = i; break; }
      }
      
      //ensure we have at least 2 at our end
      if(diff == l-1) --diff;

      for(int i = 0; i < 2; ++i) {
        cout << diff+i+1 << endl;
        cin >> left[i];
      }
      
      for(int i = 0; i < 2; ++i) {
        cout << b-diff-i << endl;
        cin >> right[(i+1)%2];
      }
      
      if(normal(left, right, diff)) { debug("NORMAL"); }
      else if(isComp(left, right, diff)) { debug("COMP"); comp(l, r); }
      else if(isFlipped(left, right, diff)) { flip(l, r);debug("flip"); }
      else { compflip(l, r); debug("compflip"); }
      
      for(int i = 0; i < 3 && n > 0; ++i) {
        cout << l+1 << endl;
        cin >> A[l];
        ++l;

        cout << r+1 << endl;
        cin >> A[r];
        --r;

        n -= 2;
      }
    }
        
    for(int& i : A) cout << i;
    cout << endl;

    char v; cin >> v;
    if(v == 'N') exit(0); 
  }
}

