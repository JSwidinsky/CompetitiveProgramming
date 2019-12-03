#include <bits/stdc++.h>
using namespace std;

int A[1005];

int main() {
    int n, l; cin >> n >> l;

    for(int i = 0; i < n; ++i) cin >> A[i];

    sort(A, A+n);

    int ans = max(A[0]*2, (l - A[n-1])*2);

    for(int i = 1; i < n; ++i) {
        ans = max(ans, abs(A[i-1] - A[i]));
    }

    cout << fixed << setprecision(10) << ans / 2.0 << endl;

}
