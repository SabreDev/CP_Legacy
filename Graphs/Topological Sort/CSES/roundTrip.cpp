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

//Problem link: https://cses.fi/problemset/task/1678

void dfs(int u, vector<int> &col, vector<vector<int>> &g, vector<int> &par, vector<int> &cycle){
	col[u] = 1;
	for(int v: g[u]){
		if(col[v]==0){
			par[v] = u;
			dfs(v, col, g, par, cycle);
		} else if(col[v]==1){
			if((int)cycle.size()==0){
				int cur = u;
				cycle.pb(u);
				while(cur != v){
					cur = par[cur];
					cycle.pb(cur);
				}
				reverse(all(cycle));
			}
			return;
		}
	}
	col[u] = 2;
}

void run_case() {
  int n,m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	rep(i,m){
		int a,b;
		cin >> a >> b;
		--a, --b;
		g[a].pb(b);
	}
	vector<int> col(n, 0);
	vector<int> par(n, -1), cycle;

	rep(i,n){
		if(col[i]==0){
			dfs(i, col, g, par, cycle);
			if((int)cycle.size()!=0){
				cycle.resize((int)cycle.size());
				cout << (int)cycle.size() + 1 << "\n";
				rep(i, (int)cycle.size())
					cout << cycle[i]+1 << " ";
				cout << cycle[0] + 1 << "\n";
				return;
			}
		}
	}
	cout << "IMPOSSIBLE";
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
