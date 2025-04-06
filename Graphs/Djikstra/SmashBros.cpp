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

//https://dmoj.ca/problem/arc1p6

const int INF = 1e9;

class Node{
	public:
		int distance;
		int city;
		bool isfree;
		Node(int d, int c, bool i): distance(d), city(c), isfree(i) {}
};

void run_case() {
	int n,m,x,y,q;
	cin >> n >> m >> x >> y >> q;
	--x, --y;
	vector<int> t(n);
	rep(i,n)
		cin >> t[i];
	vector<vector<int>> g(n);
	rep(i,m){
		int a,b;
		cin >> a >> b;
		--a, --b;
		g[a].pb(b);
		g[b].pb(a);
	}

	auto cmp = [](const Node& b, const Node& a){
		return a.distance < b.distance;
	};

	priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
	vector<vector<int>> dp1(n, vector<int>(2, INF));
	vector<vector<int>> dp2(n, vector<int>(2, INF));

	dp1[x][0] = 0;
	pq.push(Node(0,x,false));
	while(!pq.empty()){
		Node u = pq.top();
		pq.pop();
		if(dp1[u.city][(u.isfree?1:0)] != u.distance)
			continue;
		for(int v: g[u.city]){
			if(!u.isfree){
				if(dp1[u.city][1] > u.distance + t[u.city]){
					dp1[u.city][1] = u.distance + t[u.city];
					pq.push(Node(dp1[u.city][1], u.city, true));
				}
			} else {
				if(dp1[v][0] > u.distance){
					dp1[v][0] = u.distance;
					pq.push(Node(dp1[v][0], v, false));
				}
			}
		}
	}
	
	dp2[y][0] = 0;
	pq.push(Node(0,y,false));
	while(!pq.empty()){
		Node u = pq.top();
		pq.pop();
		if(dp2[u.city][(u.isfree?1:0)] != u.distance)
			continue;
		for(int v: g[u.city]){
			if(!u.isfree){
				if(dp2[u.city][1] > u.distance + t[u.city]){
					dp2[u.city][1] = u.distance + t[u.city];
					pq.push(Node(dp2[u.city][1], u.city, true));
				}
			} else {
				if(dp2[v][0] > u.distance){
					dp2[v][0] = u.distance;
					pq.push(Node(dp2[v][0], v, false));
				}
			}
		}
	}
	

	while(q--){
		int a;
		cin >> a;
		--a;
		cout << dp1[a][0] << " " << dp2[a][1] << "\n";
		//cout << dp1[a][0] + dp2[a][1] << "\n";
	}

}
 
int main() {
	fast;
	int t = 1;
  while(t--){
    run_case();
  }
}
