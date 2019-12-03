#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[100005];
bool iskcity[100005];
vector<int> cities;

int main()
{
	int n, m, k; cin >> n >> m >> k;
	
	for(int i = 0; i < m; ++i)
	{
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back(pair<int, int>(b, c));
		adj[b].push_back(pair<int, int>(a, c));
	}

	if(k == 0) { cout << -1 << endl; return 0; }

	for(int i = 0; i < k; ++i)
	{
		int a; cin >> a;
		cities.push_back(a);
		iskcity[a] = true;
	}

	int ans = -1;
	for(int& k : cities)
	{
		for(pair<int, int>& edge : adj[k])
		{
			if(!iskcity[edge.first])
			{	
				if(ans == -1) ans = edge.second;
				else ans = min(ans, edge.second);
			}
		}
	}

	cout << ans << endl;
}
