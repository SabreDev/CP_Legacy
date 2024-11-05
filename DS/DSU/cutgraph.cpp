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

//https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D

class DSU{
	public:
		int n;
		vector<int> p, sz;
		DSU(int num){
			n = num;
			p.resize(num);
			sz.resize(num,1);
			iota(all(p),0);
		}
		int get(int a){
			while(a!=p[a]){
				a=p[a];
			}
			return a;
		}
		void unite(int a, int b){
			a = get(a);
			b = get(b);
			if(a!=b){
				if(sz[a]>sz[b])
					swap(a,b);
				p[a] = b;
				sz[b]+=sz[a];
			}
		}
		bool check(int a, int b){
			return get(a)==get(b);
		}
};

void run_case(){
	int n,m,k;
	cin >> n >> m >> k;
	DSU* dsu = new DSU(n);
	rep(i,m){
		int u,v;
		cin >> u >> v;
	}
	vector<pair<string,pi>> q;
	rep(i,k){
		string type;
		int u,v;
		cin >> type >> u >> v;
		q.pb({type,{u-1,v-1}});
	}
	reverse(all(q));
	vector<string> ans;
	rep(i,k){
		if(q[i].first=="cut"){
			dsu->unite(q[i].second.first, q[i].second.second);
		} else {
			ans.pb(dsu->check(q[i].second.first, q[i].second.second)?"YES":"NO");
		}
	}
	reverse(all(ans));
	for(auto x: ans)
		cout << x << "\n";
}

int main(){
	fast;
  int t = 1;
  while(t--){
    run_case();
  }
}