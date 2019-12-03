#include <bits/stdc++.h>
using namespace std;

int A[105][105];
int B[105];

int main()
{
	int n, m; cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		--a; --b;
		A[a][b] = 1;
		A[b][a] = 1;
		++B[a];
		++B[b];
	}

	bool bad = true;
	int ans = 0;
	while(bad)
	{
		bad = false;
		vector<int> x;
		for(int i = 0; i < n; ++i)
		{
			if(B[i] == 1)
			{
				x.push_back(i);
				bad = true;
			}
		}

		if(bad) { ++ans; }
		for(int& i : x)
		{
			for(int j = 0; j < n; ++j)
			{
				if(A[i][j] == 1)
				{
					A[i][j] = 0;
					--B[i];
					A[j][i] = 0;
					--B[j];
					break;			
				}
			}
		}	
	}
	cout << ans << endl;
}
