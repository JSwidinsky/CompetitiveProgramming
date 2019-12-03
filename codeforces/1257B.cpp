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

typedef long long int ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        ll x, y; cin >> x >> y;
        
        bool b = false;
        if(x >= y) b = true;
        else if(x == 1 && y == 1) b = true;
        else if(x == 2 && (y < 4)) b = true;
        else if(x == 3 && (y < 4)) b = true;
        else if(x >= 4) b = true;

        cout << (b ? "YES" : "NO") << endl;
    }
}

