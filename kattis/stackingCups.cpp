#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    vector<pair<int, string>> V;
    for(int i = 0; i < n; ++i) {
        string s, a;
        cin >> s >> a;
        
        if(isalpha(s[0])) {
            V.push_back({stoi(a), s});
        }
        else {
            V.push_back({stoi(s) / 2, a});
        }
    }

    sort(V.begin(), V.end());

    for(auto& p : V) {
       cout << p.second << endl; 
        
    }
}
