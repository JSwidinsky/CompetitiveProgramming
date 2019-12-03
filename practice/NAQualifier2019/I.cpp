#include <bits/stdc++.h>
using namespace std;

#define bounds 505

struct Edge { int to, cost; };

unsigned long long  int mat[bounds][bounds];

vector<Edge> G[bounds];
vector<int> repair;

int main()
{
    int n, m, t, d; cin >> n >> m >> t >> d;
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            mat[i][j] =  i != j ? (1<<31) : 0;


    repair.push_back(1);
    for(int i = 0; i < t; ++i) { int a; cin >> a; repair.push_back(a); }

    repair.push_back(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        mat[a][b] = c;
        mat[b][a] = c;
    }


    for ( int k = 1; k <= n; k++ )
        for ( int i = 1; i <= n; i++ )
            for ( int j = 1; j <= n; j++)
                mat[i][j]= min( mat[i][j],mat[i][k]+ mat[k][j]);


    for(int& r : repair)
    {
        for(int& r2 : repair)
        {
            Edge e;
            e.to = r2;
            e.cost = mat[r][r2];
            G[r].push_back(e);
        }
    }

    typedef pair<int, int> pii;

    bool discovered[bounds];
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(pii(0, 1));
    while(!q.empty())
    {
        pii next = q.top(); q.pop();
        
        int node = next.second, cost = next.first;
        if(!discovered[node])
        {
            discovered[node] = true;

            if(node == n) { cout << cost << endl; return 0; }
            for(Edge& e : G[node])
            {
                if(e.cost <= d)
                    q.push(pii(cost + e.cost, e.to));    
            }
        }
    }

    cout << "stuck" << endl;
}
