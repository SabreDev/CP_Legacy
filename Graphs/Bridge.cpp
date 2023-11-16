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

//Finding bridges in a graph. Same algorithm as finding articulation points. However we dont care about the root here and the equality condition lv = tu.
//As on this condition the back edge will be on u itself hence u-v cant be a bridge.
//Also this does not handle multiple edges, we can process edges as pairs of vertex, index to handle that case when required.

void dfs(int par, int u, vector<vector<int>> &g, vector<int> &tin, vector<int> &low, vector<bool> &vis, int time){
  tin[u] = time;
  vis[u] = true;
  for(int v: g[u]){
    if(!vis[v]){
      dfs(u, v, g, tin, low, vis, time + 1);
      low[u] = min({low[u], low[v], tin[u]});
      if(low[v] > tin[u]){
        cout << u + 1 << " " << v + 1 << "\n";
      }
      
    } else if (v != par){
      low[u] = min(low[u], tin[v]);
    }
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
  vector<bool> vis(N, false);
  dfs(-1, 0, g, tin, low, vis, 1);

}

int main() {
  fast;
	int t=1;
  while(t--){
    run_case();
	}
}
