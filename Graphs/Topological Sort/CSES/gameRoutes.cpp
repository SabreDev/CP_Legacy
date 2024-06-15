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

//Problem link: https://cses.fi/problemset/task/1681

void run_case() {
  int n,m;
	int mod = 1e9 + 7;
	cin >> n >> m;
	vector<vector<int>> g(n), back(n);
	vector<int> in(n,0);
	rep(i,m){
		int a,b;
		cin >> a >> b;
		--a,--b;
		g[a].pb(b);
		back[b].pb(a);
		++in[b];
	}
	queue<int> q;
	rep(i,n){
		if(in[i]==0)
			q.push(i);
	}
	vector<int> topo_sort;
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

	topo_sort.resize(n);
	vector<int> dp(n, 0);
	dp[0]=1;

	rep(i,n){
		int v = topo_sort[i];
		for(int u: back[v]){
			dp[v]+=dp[u];
			if(dp[v]>=mod)
				dp[v]-=mod;
		}
	}
	cout << dp[n-1] << "\n";
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
