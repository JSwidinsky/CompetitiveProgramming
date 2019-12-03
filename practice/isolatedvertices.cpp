#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m; cin >> n >> m;
	int minVal, maxVal;

	minVal = max(0, n - (m * 2));

	int iterations = 1;
	int sum = 1;
	if(m == 1)
	{
		maxVal = n - 2;
	}
	else
	{
		while(sum < m)
		{
			++iterations;
	
			sum = (iterations * (iterations - 1)) / 2;
		}

		maxVal = n - iterations;
	}
	cout << minVal << " " << maxVal << endl;

}
