#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    int n; cin >> n;

    vector<double> V;
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        double a; cin >> a;

        V.push_back(a);
    }

    sort(V.begin(), V.end());

    double ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += V[i] * (n-i);
    }

    cout << fixed << setprecision(4) << ans << endl;

}
