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

vector<vector<int>> P(50);
vector<int> ptr(50, 0);

int main() {
     int n; cin >> n;
     vector<int> A(n);

     for(int& x : A) cin >> x;

     for(int i = 0; i < n; ++i) {
          P[A[i]].push_back(i);
     }

     bool b = true;

     while(b) {
          vector<int> inserted;
          for(int i : {4, 8, 15, 16, 23, 42}) {
               if(ptr[i] < P[i].size()) {
                    ++ptr[i];
                    inserted.push_back(i);
               }
               else {
                    b = false;
                    for(int j : inserted) --ptr[j];
                    break;
               }
          }
     }
     
     int remaining = 0;
     for(int i : {4, 8, 15, 16, 23, 42}) {
          remaining += (P[i].size() - ptr[i]);
     }

     cout << remaining << endl;


}