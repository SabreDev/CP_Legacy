//Intersection of 2 line segments.
pair<int,int> intersection(int l1, int r1, int l2, int r2){
	if(l1 <= l2){
		if(r1 < l2){
			return {-1, -1};
		}
		return {l2, min(r1, r2)};
	} else {
		if(r2 < l1) {
			return  {-1, -1};
		}
		return {l1, min(r1, r2)};
	}
}

//Djiksta
ll INF = 1e15;
set<pi> q;
q.insert({0, 0});
vector<ll> d(n, INF);
d[0] = 0;
while(!q.empty()){
	ll u = q.begin()->S;
	q.erase(q.begin());
	for(pi v: g[u]){
		if(d[u] + v.S < d[v.F]){
			q.erase({d[v.F], v.F});
			d[v.F] = d[u] + v.S;
			q.insert({d[v.F], v.F});
		}
	}
}

//Recursive lambda
function<void(int,int)> dfs1, dfs2; //have to use function else throw error: use of dfs1 before deduction of auto.
	auto dfs1 = [&](int u, int p) -> void {
		par[u] = p;
		for(int v: g[u]){
			if(v!=p){
				dfs1(v, u);
				here[u]+=here[v];
			}
		}
	};
dfs1(0, -1);

//Non recursive lambda
auto f = [&](int m) -> bool{
      int lb = lower_bound(all(a), b - m) - a.begin();
      int ub = upper_bound(all(a), b + m) - a.begin();
      return ub - lb >= k;
};

//Extended euclidean with co-effs:
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

//Decide when to print \n
cout << ans[i] << " \n"[i == n - 1];