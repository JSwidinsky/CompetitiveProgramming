#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[100005];
pair<unsigned long long int, int> cost[100005];
bool discovered[100005];

bool f(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; ++i) 
	{	
		unsigned long long int a; cin >> a;
		cost[i] = pair<unsigned long long int, int>(a, i);
	}

	for(int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
		
	queue<int> q;

	unsigned long long int ans = 0;	
	for(int i = 1; i <= n; ++i)
	{
		if(!discovered[i])
		{
			queue<int> q;
			q.push(i);
			unsigned long long int minCost = cost[i].first;

			while(!q.empty())
			{
				int node = q.front();
				q.pop();

				minCost = min(minCost, cost[node].first);
				
				discovered[node] = true;
				for(int& j : adjList[node])
				{
					if(!discovered[j])
					{
						q.push(j);
					}
				}	
			}

			ans += minCost;
		}
	}
	cout << ans << endl;
}
