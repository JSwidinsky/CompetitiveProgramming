//max flow

#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { 
  o << "(" << x.fst << ", " << x.snd << ")"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o;
}

template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o;
}

struct Edge;
typedef list<Edge>::iterator EdgeIter;

struct Edge {
  int to;
  int cap;
  int flow;
  bool is_real;
  EdgeIter partner;
  
  Edge(int t, int c, bool real = true)
    : to(t), cap(c), flow(0), is_real(real)
  {};

  int residual() const
  {
    return cap - flow;
  }
};

struct Graph {
  list<Edge> *nbr;
  int num_nodes;
  Graph(int n)
    : num_nodes(n)
  {
    nbr = new list<Edge>[num_nodes];
  }

  ~Graph()
  {
    delete[] nbr;
  }

  // note: this routine adds an edge to the graph with the specified capacity,
  // as well as a residual edge.  There is no check on duplicate edge, so it
  // is possible to add multiple edges (and residual edges) between two
  // vertices
  void add_edge(int u, int v, int cap)
  {
    nbr[u].push_front(Edge(v, cap));
    nbr[v].push_front(Edge(u, 0, false));
    nbr[v].begin()->partner = nbr[u].begin();
    nbr[u].begin()->partner = nbr[v].begin();
  }
};

void push_path(Graph &G, int s, int t, const vector<EdgeIter> &path, int flow)
{
  for (int i = 0; s != t; i++) {
    if (path[i]->is_real) {
      path[i]->flow += flow;
      path[i]->partner->cap += flow;
    } else {
      path[i]->cap -= flow;
      path[i]->partner->flow -= flow;
    }
    s = path[i]->to;
  }
}

// the path is stored in a peculiar way for efficiency: path[i] is the
// i-th edge taken in the path.
int augmenting_path(const Graph &G, int s, int t, vector<EdgeIter> &path,
		    vector<bool> &visited, int step = 0)
{
  if (s == t) {
    return -1;
  }
  for (EdgeIter it = G.nbr[s].begin(); it != G.nbr[s].end(); ++it) {
    int v = it->to;
    if (it->residual() > 0 && !visited[v]) {
      path[step] = it;
      visited[v] = true;
      int flow = augmenting_path(G, v, t, path, visited, step+1);
      if (flow == -1) {
	return it->residual();
      } else if (flow > 0) {
	return min(flow, it->residual());
      }
    }
  }
  return 0;
}

// note that the graph is modified
int network_flow(Graph &G, int s, int t)
{
  vector<bool> visited(G.num_nodes);
  vector<EdgeIter> path(G.num_nodes);
  int flow = 0, f;

  do {
    fill(visited.begin(), visited.end(), false);
    if ((f = augmenting_path(G, s, t, path, visited)) > 0) {
      push_path(G, s, t, path, f);
      flow += f;
    }
  } while (f > 0);
  
  return flow;
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  cin.ignore(); cin.ignore();
  int b = 0;
  while(t--) {
    if(b) cout << endl;
    b = 1;

    map<string, int> names, parties, clubs;
    int c = 2; 
    
    vector<vector<string>> V;
    int cnt = 0;
    string s;
    
    //get input and count number of nodes
    while(getline(cin, s) && s != "") {
      istringstream iss(s);
      string name, party; iss >> name >> party;
      
      names[name] = c++;
      if(!parties.count(party)) parties[party] = c++;
          
      V.push_back({});
      V[cnt].push_back(name);
      V[cnt].push_back(party);
    
      string club;
      while(iss >> club) {
        if(!clubs.count(club)) clubs[club] = c++;

        V[cnt].push_back(club);
      }

      ++cnt;
    }

    Graph G(c + 5);

    //actually build the graph
    for(auto& S : V) {
      int name = names[S[0]], party = parties[S[1]];
      
      G.add_edge(name, party, 1);

      for(int i = 2; i < S.size(); ++i) {
        int club = clubs[S[i]];
        G.add_edge(club, name, 1);
      }
    }

    for(auto& p : clubs) {
      G.add_edge(0, p.second, 1);
    }

    for(auto& p : parties) {
      G.add_edge(p.second, 1, (clubs.size()-1)/2);
    }

    int flow = network_flow(G, 0, 1);

    if(flow != clubs.size()) { cout << "Impossible." << endl; continue; }
    
    //the way I did things made this part pretty gross...
    for(auto& p : clubs) {
      for(auto& e : G.nbr[p.second]) {
        if(e.is_real && e.flow > 0) {
          for(auto& p2 : names) {
            if(p2.second == e.to) cout << p2.first << " ";
          }
          cout << p.first << endl;
        }
      }
    }
  }  
}

