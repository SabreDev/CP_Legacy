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

//Problem link: https://codeforces.com/contest/1627/problem/C

void run_case() {
	int n;
	cin >> n;
	vector<vector<pi>> g(n);
	rep(i,n-1){
		int u,v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(mp(v, i));
		g[v].pb(mp(u, i));
	}
	
	rep(i,n){
		if((int)g[i].size()>2){
			cout << -1 << "\n";
			return;
		}
	}

	int st;
	rep(i,n){
		if((int)g[i].size()==1){
			st = i;
			break;
		}
	}

	bool ok = true;
	int f = 1;
	pi u = mp(st, -1);
	int prev = -1;
	vector<int> ans(n);

	int cnt = 0;
	while(ok){
		ok = false;
		for(int i=0;i<(int)g[u.F].size();++i){
			if(g[u.F][i].F != prev){
				ok = true;
				ans[g[u.F][i].S] = f ? 2 : 3;
				f^=1;
				prev = u.F;
				u.F = g[u.F][i].F;
			}
		}
	}
	rep(i,n-1)
		cout << ans[i] << " ";
	
	cout << '\n';
}
 
int main() {
  fast;
  int t;
	cin >> t;
  while(t--){
    run_case();
  }
}
