#include <bits/stdc++.h>
using namespace std;

vector<int> G[40000];

int main()
{
    int n, m; cin >> n >> m;
    
    for(int i = 10000; i >= 1; --i)
    {
        G[i].push_back(i*2);
    }

    for(int i = 10000; i >= 1; --i)
    {
        G[i].push_back(i-1);    
    }


    typedef pair<int, int> pii;

    queue<pii> q;
    vector<bool> discovered(20100, false);

    q.push(pii(n, 0));

    while(!q.empty())
    {
        pii top = q.front();
        q.pop();

        int node = top.first, c = top.second;
        if(node == m) { cout << c << endl; return 0; }
        if(!discovered[node])
        {
            discovered[node] = true;

            for(int& edge : G[node])
            {
                q.push(pii(edge, c+1));

            }
        }
    }

}
