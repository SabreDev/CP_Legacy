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

//https://codeforces.com/contest/1915/problem/G

const ll INF = 1e15;

class Node{
	public:
		ll distance;
		int city;
		int bicycle;
		Node(ll d, int c, int b){
			distance = d;
			city = c;
			bicycle = b;
		}
		bool operator<(const Node& other) const {
			//Should go through all parameters in order to put the key in set appropriately.
			if (distance != other.distance)
          return distance < other.distance;
			if (city != other.city)
					return city < other.city;
			return bicycle < other.bicycle;
		}
};

void run_case() {
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> g(n);
	rep(i,m){
		int a,b,w;
		cin >> a >> b >> w;
		--a,--b;
		g[a].pb({b,w});
		g[b].pb({a,w});
	}
	vector<int> s(n);
	rep(i,n)
		cin >> s[i];

	vector<vector<ll>> d(n, vector<ll>(n, INF));
	d[0][0] = 0;
	
	set<Node> q;
	q.insert(Node(d[0][0], 0, 0));

	while(!q.empty()){
		Node u = *q.begin();
		vector<int> poss_bicycles = {u.bicycle};
		if(u.bicycle != u.city)
			poss_bicycles.pb(u.city);
		
		q.erase(q.begin());
		for(auto v: g[u.city]){
			int to = v.F;
			int w = v.S;
			for(int cur_bicycle: poss_bicycles){
				if(d[to][cur_bicycle] > u.distance + 1LL*s[cur_bicycle]*w){
					q.erase(Node(d[to][cur_bicycle], to, cur_bicycle));
					d[to][cur_bicycle] = u.distance + 1LL*s[cur_bicycle]*w;
					q.insert(Node(d[to][cur_bicycle], to, cur_bicycle));
				}
			}
		}
	}

	ll ans = INF;
	rep(i,n){
		ans=min(ans, d[n-1][i]);
	}
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
