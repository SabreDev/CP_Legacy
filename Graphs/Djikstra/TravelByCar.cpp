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

//https://atcoder.jp/contests/abc143/tasks/abc143_e

const int INF = 1e9;
bool cmp(const pair<int,ll> &x, const pair<int,ll> &y){
    if(x.first == y.first) return x.second > y.second;
    return x.first < y.first;
}

class Node{
	public:
		int distance;
		int city;
		ll fuel;
		Node(int d, int c, ll f): distance(d), city(c), fuel(f) {}
		bool operator<(const Node &x) const{
        if(distance == x.distance) return fuel < x.fuel;
        return distance > x.distance;
    }
};

void run_case() {
	int n,m,l;
	cin >> n >> m >> l;
	vector<vector<pair<int,int>>> g(n);
	rep(i,m){
		int a,b,w;
		cin >> a >> b >> w;
		--a, --b;
		if(w<=l){
			g[a].pb({b,w});
			g[b].pb({a,w});
		}
	}
	priority_queue<Node, vector<Node>> q;
	vector<vector<int>> fdist(n);

	rep(i,n){
		//dp[i].F -> min refuelling required to reach i.
		//dp[i].S -> remaining fuel to reach i.
		vector<pair<int,ll>> dp(n, {INF, -INF});

		dp[i] = {0, l};

		q.push(Node(0,i,l));

		while(!q.empty()){
			Node u = q.top();
			q.pop();
			if(dp[u.city].F != u.distance || dp[u.city].S != u.fuel)
				continue;
			for(auto [v, w]: g[u.city]){
				if(u.fuel>=w && cmp({u.distance, u.fuel - w}, dp[v])){
					dp[v] = {u.distance, u.fuel - w};
					q.push(Node(u.distance, v, u.fuel - w));
				} else if(u.fuel < w && cmp({u.distance + 1, l - w}, dp[v])){
					dp[v] = {u.distance + 1, l - w};
					q.push(Node(u.distance + 1, v, l - w));
				}
			}
		}
		rep(j,n){
			fdist[i].pb((dp[j].F==INF)?-1:dp[j].F);
		}
		fdist[i].resize(n);
	}

	int que;
	cin >> que;
	rep(i,que){
		int s,t;
		cin >> s >> t;
		--s,--t;
		int ans = fdist[s][t];
		if(ans==INF)
			ans = -1;
		cout << ans << "\n";
	}

}
 
int main() {
	fast;
	int t = 1;
  while(t--){
    run_case();
  }
}
