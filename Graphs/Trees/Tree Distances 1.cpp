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
const int maxN = 200001;

int a_f[maxN]; //First best/longest path from a vertex.
int a_s[maxN]; //Second best/longest path from a vertex.
int f[maxN]; //f[a]=b indicates that the best/longest path from a goes through b.

//Calculate max for every node v such that path passes through child of v in a bottom up manner.
void dfs1(int u, int par, vector<vector<int>> &g){
  a_f[u] = 0;
  a_s[u] = 0;
  for(int v : g[u]){
    if(v==par) continue;
    dfs1(v,u,g);
    if(a_f[v] + 1 > a_f[u]){
      a_s[u] = a_f[u];
      a_f[u] = a_f[v] + 1;
      f[u] = v;
    } else {
      a_s[u] = max(a_s[u], a_f[v] + 1);
    }
  }
}

//Calculate max for every node v such that path passes through parent of v in a top-down manner.
//We know first best and second best paths for root. Using that information we can calculate the final
//first and second best paths for its children and then visit the children.
//We follow the same pattern for the consequent parent-child pairs. For leaf nodes our answer will already be calucualted in its parent iteration.
void dfs2(int u, int par, vector<vector<int>> &g){
  for(int v : g[u]){
    if(v==par) continue;
    if(f[u]==v){
      if(a_s[u] + 1 > a_f[v]){
        a_s[v] = a_f[v];
        a_f[v] = a_s[u] + 1;
        f[v] = u;
      } else {
        a_s[v] = max(a_s[v], a_s[u] + 1);
      }
    } else {
      //Since fu != v there is a longer path not going through v, so we update the first best to it and the second best to the current first best.
        a_s[v] = a_f[v];
        a_f[v] = a_f[u] + 1;
        f[v] = u;
    }
    dfs2(v,u,g);
  }
}


void run_case() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    --a, --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs1(0,-1,g);
  dfs2(0,-1,g);
  rep(i,n)
    cout << a_f[i] << " ";

}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
	}
}