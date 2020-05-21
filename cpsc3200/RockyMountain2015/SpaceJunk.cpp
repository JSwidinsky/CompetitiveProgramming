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

/*
Mathy type problem
we are looking for solutions to a quadratic equation 
if there are no real roots, then there is no collision
otherwise the negative root
*/

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;

  cout << fixed << setprecision(5);
  while(t--) {
    int x1, y1, z1, x2, y2, z2;
    int vx, vy, vz, ux, uy, uz;
    int r1, r2;

    cin >> x1 >> y1 >> z1 >> r1 >> vx >> vy >> vz;
    cin >> x2 >> y2 >> z2 >> r2 >> ux >> uy >> uz;
    
    //this is the hard way to do this, but I was trying to stay organized...
    int dx = x1 - x2;
    int dy = y1 - y2;
    int dz = z1 - z2;
    int dvx = vx - ux;
    int dvy = vy - uy;
    int dvz = vz - uz;

    int a = dvx*dvx + dvy*dvy + dvz*dvz;
    int b = 2*(dx*dvx + dy*dvy + dz*dvz);
    int c = dx*dx + dy*dy + dz*dz - (r1 + r2)*(r1 + r2);

    int discr = b*b - 4*a*c;
    if(discr < 0 || a == 0) cout << "No collision" << endl;
    else {
      double rt1 = (-b - sqrt(discr))/(2.0f*a);
      double rt2 = (-b + sqrt(discr))/(2.0f*a);

      if(rt2 < 0) { cout << "No collision" << endl; }
      else {
        cout << fixed << setprecision(4) << rt1 << endl;
      }
    }
  }
}

