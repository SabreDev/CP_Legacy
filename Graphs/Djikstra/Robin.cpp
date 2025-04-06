#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi pair<ll,ll>
#define pii pair<int,pi>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define cusrep(i,a,b,j) for(int i=a;i<b;i+=j)
#define rng(i,a,b) for(int i=a;i<b;i++)
#define rrng(i,a,b) for(int i=a;i>b;--i)
#define ar array

//https://codeforces.com/contest/2014/problem/E

const ll INF = 1e15;

class Node{
	public:
		ll distance;
		int horse_id;
		int city;
		Node(ll d, int h, int c): distance(d), horse_id(h), city(c) {}
};

class DpNode{
	public:
		ll distance;
		int horse_id;
		DpNode(ll d, int h): distance(d), horse_id(h) {}

};

vector<vector<DpNode>> djikstra(int start, vector<vector<pair<int,int>>> &g, vector<bool> &is, int n){
	auto cmp = [](const Node& a, const Node& b){
		return a.distance > b.distance;
	};

	priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
	vector<vector<DpNode>> dp(n, vector<DpNode>(2, DpNode(INF, -1)));

	dp[start][0] = DpNode(0, -1);
	pq.push(Node(0,-1,start));

	while(!pq.empty()){
		Node u = pq.top();
		pq.pop();
		if(dp[u.city][(u.horse_id>-1?1:0)].distance!=u.distance)
			continue;
		for(auto [v, w]: g[u.city]){
			if(u.horse_id != -1){
				if(dp[v][1].distance > u.distance + w/2){
					dp[v][1] = DpNode(u.distance + w/2, u.horse_id);
					pq.push(Node(u.distance + w/2, u.horse_id, v));
				}
			} else {
				if(dp[v][0].distance > u.distance + w){
					dp[v][0].distance = u.distance + w;
					pq.push(Node(u.distance + w, u.horse_id, v));
				}
				if(is[u.city]){
					if(dp[u.city][1].distance > u.distance){
						dp[u.city][1] = DpNode(u.distance, u.city);
						pq.push(Node(u.distance, u.city, u.city));
					}
				}
			}
		}
	}
	return dp;
}



void run_case() {
	int n,m,h;
	cin >> n >> m >> h;
	vector<bool> is(n, false);
	vector<vector<pair<int,int>>> g(n);
	
	rep(i,h){
		int a;
		cin >> a;
		--a;
		is[a] = true;
	}
	rep(i,m){
		int u,v,w;
		cin >> u >> v >> w;
		--u, --v;
		g[u].pb({v, w});
		g[v].pb({u, w});
	}

	vector<vector<DpNode>> dp1 = djikstra(0,g,is,n);
	vector<vector<DpNode>> dp2 = djikstra(n-1,g,is,n);

	ll ans = INF;
	rep(i,n){
		rep(j,2){
			rep(k,2){
				ans = min(ans, max(dp1[i][j].distance, dp2[i][k].distance));
			}
		}
	}
	if(ans==INF)
		ans=-1;
	cout << ans << "\n";

}
 
int main() {
	fast;
	int t;
	cin >> t;
  while(t--){
    run_case();
  }
}
