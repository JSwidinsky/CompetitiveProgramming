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

stack<int> S;

void spacespace(string s, int& i) {
  int r;
  string t;
  int currbit = 0;
  while(s[i] != 'N') {
    t += s[i];
    ++i;
  }
  
  for(int j = t.length()-1; j >= 1; --j) {
    if(t[j] != 'S') {
      r = (r | (1 << currbit));
    }
    ++currbit;
  }
  ++i;
  if(t[0] == 'T') r *= -1;
  S.push(r);
}

void spacenewline(string s, int i) {
  if(s[i] == 'S') {
    if(S.empty()) {
      cout << "Invalid copy operation" << endl;
    }
    else {
      int c = S.top();
      S.push(c);
    }
  }
  else if(s[i] == 'T') {
    if(S.size() < 2) {
      cout << "Invalid swap operation" << endl;
    }
    else {
      int first = S.top(); S.pop();
      int second = S.top(); S.pop();
      S.push(first); S.push(second);
    }
  }
  else {
    if(S.empty()) {
      cout << "Invalid remove operaton" << endl;
    }
    else {
      S.pop();
    }
  } 
}

void tabspacespace(string s, int i) {
  if(s[i] == 'S') {
    if(S.size() < 2) {
      cout << "Invalid addition operation" << endl;
    }
    else {
      int a = S.top(); S.pop();
      int b = S.top(); S.pop();
      S.push(a+b);
    }
  }
  else if(s[i] == 'T') {
    if(S.size() < 2) {
      cout << "Invalid subtraction operation" << endl;
    }
    else {
      int a = S.top(); S.pop();
      int b = S.top(); S.pop();
      S.push(b-a);
    }
  }
  else {
    if(S.size() < 2) {
      cout << "Invalid multiplication operation" << endl;
    }
    else {
      int a = S.top(); S.pop();
      int b = S.top(); S.pop();
      S.push(a*b);
    }
  }
}

void tabspacetab(string s, int i) {
    if(S.size() < 2) {
      cout << "Invalid division operation" << endl;
    }
    else {
      int a = S.top(); S.pop();
      int b = S.top(); S.pop();
      if(a == 0) {
        cout << "Division by zero" << endl;
      }
      else {
        S.push(b/a);
      }
    } 
}

void tabnewlinespacetab(string s, int i) {
  if(S.empty()) {
    cout << "Invalid print operation" << endl;
  }
  else {
    cout << S.top() << endl;
    S.pop();
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  string s; cin >> s;

  for(int i = 0; i < s.length(); i) {
    if(s[i] == 'S') {
      if(s[i+1] == 'S') { i += 2; spacespace(s, i); }
      else { spacenewline(s, i+2); i += 3; }
    }
    else if(s[i] == 'T') {
      if(s[i+1] == 'S' && s[i+2] == 'S') { tabspacespace(s, i+3); i += 4; }
      else if(s[i+1] == 'S' && s[i+2] == 'T') { tabspacetab(s, i+4); i += 4; }
      else { tabnewlinespacetab(s, i); i += 4; }
    }
  }
}

