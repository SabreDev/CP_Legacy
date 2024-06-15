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
#define cusrep(i,a,b,j) for(int i=a;i<b;i+=j)
#define rng(i,a,b) for(int i=a;i<b;i++)
#define rrng(i,a,b) for(int i=a;i>b;--i)
#define ar array

//Problem link: https://open.kattis.com/problems/quantumsuperposition

vector<vector<bool>> run_case(vector<vector<int>> &g, vector<int> &in, int n) {
  vector<int> topo_sort;

  vector<vector<int>> _g(n);
  rep(i,n){
    for(int x: g[i]){
      _g[x].pb(i);
    }
  }

  queue<int> q;
  rep(i,n){
    if(in[i]==0)
      q.push(i);
  }

  while(!q.empty()){
    int u = q.front();
    topo_sort.pb(u);
    q.pop();
    for(int v: g[u]){
      --in[v];
      if(in[v]==0){
        q.push(v);
      }
    }
  }

  vector<vector<bool>> dp(n, vector<bool>(2001, false));
  dp[0][0] = true;

  for(int cur: topo_sort){
    for(int prev: _g[cur]){
      rng(k, 1, 2001){
        dp[cur][k] = dp[cur][k] | dp[prev][k-1];
      }
    }
  }
  return dp;
}
 
int main() {
  fast;

  int n1,n2,m1,m2;
  cin >> n1 >> n2 >> m1 >> m2;
  vector<vector<int>> g1(n1);
  vector<int> in1(n1, 0);
  vector<vector<int>> g2(n2);
  vector<int> in2(n2,0);

  rep(i,m1){
    int u,v;
    cin >> u >> v;
    --u, --v;
    g1[u].pb(v);
    ++in1[v];
  }
  rep(i,m2){
    int u,v;
    cin >> u >> v;
    --u, --v;
    g2[u].pb(v);
    ++in2[v];
  }

  vector<vector<bool>> dp1 = run_case(g1, in1, n1);
  dp1.resize((int)dp1.size());
  vector<vector<bool>> dp2 = run_case(g2, in2, n2);
  dp2.resize((int)dp2.size());

  unordered_set<int> poss;
  rep(i,2001){
    rep(j,2001){
      if(dp1[n1-1][i] && dp2[n2-1][j])
        poss.insert(i+j);
    }
  }

  int q;
  cin >> q;
  while(q--){
    int x;
    cin >> x;
    if(poss.count(x)>0)
      cout << "Yes";
    else
      cout << "No";
    cout << "\n";
  }

  
}
