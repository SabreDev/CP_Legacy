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
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

void run_case() {
	setIO("milkorder");
	int n,m;
	cin >> n >> m;
	vector<vector<int>> obs(m);
	rep(i,m){
		int t;
		cin >> t;
		rep(j,t){
			int x;
			cin >> x;
			--x;
			obs[i].pb(x);
		}
		obs[i].resize((int)obs[i].size());
	}

	int l=1,h=m;
	auto cmp = [](const int &b, const int &a){
		return a < b;
	};

	vector<int> ans;
	rep(i,n){
		ans.pb(i);
	}
	
	while(l<=h){
		int mid = (l+h)/2;
		vector<vector<int>> g(n);
		vector<int> in(n, 0);
		rep(i,mid){
			int sz = obs[i].size();
			rep(j,sz-1){
				g[obs[i][j]].pb(obs[i][j+1]);
				++in[obs[i][j+1]];
			}
		}
		vector<int> topo_sort;
		priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
		rep(i,n){
			if(in[i]==0){
				pq.push(i);
			}
		}
		while(!pq.empty()){
			int u = pq.top();
			topo_sort.pb(u);
			pq.pop();
			for(int v: g[u]){
				--in[v];
				if(in[v]==0){
					pq.push(v);
				}
			}
		}
		if((int)topo_sort.size()!=n){
			h = mid - 1;
		} else {
			l = mid + 1;
			ans = topo_sort;
		}
	}
	ans.resize(n);
	rep(i,n)
		cout << ans[i] + 1 << (i<n-1 ? " " : "");
}
 
int main() {
  fast;
	int t = 1;
  while(t--){
    run_case();
  }
}
