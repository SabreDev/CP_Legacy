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

void run_case() {
  int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<vector<int>> g(n), _g(n);
	vector<int> in(n, 0);
	rep(i,m){
		int u,v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		++in[v];
		_g[v].pb(u);
	}
	queue<int> q;
	rep(i,n){
		if(in[i]==0)
			q.push(i);
	}
	vector<int> topo_sort;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		topo_sort.pb(u);
		for(int v: g[u]){
			--in[v];
			if(in[v]==0)
				q.push(v);
		}
	}
	if(topo_sort.size()!=n){
		cout << -1 << "\n";
		return;
	}
	topo_sort.resize(n);
	vector<vector<int>> dp(n, vector<int>(26,0));

	for(int cur: topo_sort){
		dp[cur][(int)(s[cur]-'a')] = max(dp[cur][(int)(s[cur]-'a')], 1);
		for(int prev: _g[cur]){
			rep(i, 26){
				int x = ((int)(s[cur]-'a')==i) ? 1 : 0;
				dp[cur][i] = max(dp[cur][i], dp[prev][i] + x);
			}
		}
	}
	int ans = 0;
	rep(i,n){
		rep(j,26)
			ans=max(ans, dp[i][j]);
	}
	cout << ans << "\n";
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
