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