#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define pii pair<int,pi>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define rng(i,a,b) for(int i=a;i<b;i++)
#define ar array

//Finding articulation points using Tarjans algorithm.
//Articulation points are those points which when removed from graph alongwith all its connecting edges splits the graph into multiple components of size > 1
//Consider any parent-child edge in dfs tree.
//When there is an edge from any vertex in subtree of children to any ancestor of the parent (aka back-edge) then the parent is not an articulation point else it is.
//We can maintain an array low which indicates the earliest time for all vertices when they were first accessible via a back-edge.

void dfs(int par, int u, vector<vector<int>> &g, vector<int> &tin, vector<int> &low, vector<bool> &isAP, vector<bool> &vis, int time){
  tin[u] = time;
  vis[u] = true;
  int children = 0;
  for(int v: g[u]){
    if(!vis[v]){
      ++children;
      dfs(u, v, g, tin, low, isAP, vis, time + 1);
      low[u] = min({low[u], low[v], tin[u]});
      if(par != -1 && low[v] >= tin[u]){
        isAP[u] = true;
      }
    } else if (v != par){
      low[u] = min(low[u], tin[v]);
    }
  }
  if(par == -1 && children > 1){
    isAP[u] = true;
  }
}

void run_case() {
  int N, M, u, v;
  cin >> N >> M;
  vector<vector<int>> g(N);
  rep(i, M){
    cin >> u >> v;
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }

  vector<int> tin(N, 0);
  vector<int> low(N, 1e9);
  vector<bool> isAP(N, false);
  vector<bool> vis(N, false);
  dfs(-1, 0, g, tin, low, isAP, vis, 1);
  rep(i, N){
    if(isAP[i]){
      cout << i+1 << " ";
    }
  }
  cout << "\n";

}

int main() {
  fast;
	int t=1;
  while(t--){
    run_case();
	}
}
