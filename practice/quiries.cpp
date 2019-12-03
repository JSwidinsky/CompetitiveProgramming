#include <bits/stdc++.h>
using namespace std;

int sum[100005];
int A[100005];

int main()
{
	string s; cin >> s;
	int m; cin >> m;

	for(int i = 0; i < s.length()-1; ++i)
	{
		if(s[i] == s[i+1]) A[i+1] = 1;
	}

	sum[0] = 0;
	for(int i = 1; i < s.length(); ++i)
	{
		sum[i] = sum[i-1] + A[i];
	}

	for(int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		--a; --b; 
		cout << sum[b] - sum[a] << endl;
	}
}
