#include<bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  cin.ignore();
  set<string> S;
  for(int i = 0; i < n; ++i) {
    string s; getline(cin, s);
    
    for(int j = 0; j < s.length(); ++j) {
      if(s[j] == '-') s[j] = ' ';
      else s[j] = tolower(s[j]);
    }

    S.insert(s);
  }

  cout << S.size() << endl;
}
