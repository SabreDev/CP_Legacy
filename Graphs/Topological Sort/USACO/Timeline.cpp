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

//Problem link: https://usaco.org/index.php?page=viewproblem2&cpid=1017

void run_case() {
	ifstream fin("timeline.in");
	int n,m,c;
	fin >> n >> m >> c;
	vector<int> s(n);
	rep(i,n)
		fin >> s[i];
	vector<vector<pair<int,int>>> g(n), _g(n);
	vector<int> in(n, 0);
	rep(i,c){
		int a,b,x;
		fin >> a >> b >> x;
		--a, --b;
		g[a].pb(mp(b,x));
		++in[b];
		_g[b].pb(mp(a,x));
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
		for(pi v: g[u]){
			--in[v.F];
			if(in[v.F]==0)
				q.push(v.F);
		}
	}
	vector<ll> dp(n);
	rep(i,n)
		dp[i] = s[i];
	
	for(int cur: topo_sort){
		for(pi prev: _g[cur]){
			dp[cur]=max(dp[cur], dp[prev.F] + prev.S);
		}
	}

	ofstream fout("timeline.out");
	rep(i,n)
		fout << dp[i] << "\n";

}
 
int main() {
  fast;
	
	int t = 1;
  while(t--){
    run_case();
  }
}
