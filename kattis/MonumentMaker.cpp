#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, w; cin >> n >> d >> w;
    
    string s, t;
    for(int i = 0; i < n; ++i) {
        cin >> t;
        if(i % 2 == 1) reverse(t.begin(), t.end());

        s += t;
    }

    int ans = 0;
    int i;
    for(i = w; i < s.length(); i += w) {
        int j;
        if(s[i] == '.') {
            ++ans;
            ++i;
        }
        else {
            for(j = i; j; --j) {
                if(s[j] == '.') {
                    i = j+1;
                    ans++;
                    break;
                }
            }
        }
    }

    if(i > s.length()) ++ans;
    cout << ans << endl;    
}
