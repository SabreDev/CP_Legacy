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

//link: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B

class DSU {
	public:
		int n;
		vector<int> p, sz, mn, mx;
		DSU(int num){
			n = num;
			p.resize(num);
			sz.resize(num, 1);
			mn.resize(num);
			mx.resize(num);
			iota(all(mn), 0);
			iota(all(mx), 0);
			iota(all(p), 0);
		}
		int get(int a){
			while(a != p[a]){
				a = p[a];
			}
			return a;
		}
		void unite(int a, int b){
			a = get(a);
			b = get(b);
			if(a!=b){
				if(sz[a] > sz[b])
					swap(a,b);
				p[a] = b;
				sz[b]+=sz[a];
				mx[b] = max(mx[b], mx[a]);
				mn[b] = min(mn[b], mn[a]);
			}
		}
		int get_sz(int id){
			return sz[id];
		}
		int get_mn(int id){
			return mn[id];
		}
		int get_mx(int id){
			return mx[id];
		}
};
void run_case(){
	int n,m;
	cin >> n >> m;
	DSU* dsu = new DSU(n);
	string type;
	int a,b;
	while(m--){
		cin >> type;
		if(type=="union"){
			int a,b;
			cin >> a >> b;
				--a, --b;
			dsu->unite(a,b);
		} else {
			int a;
			cin >> a;
			--a;
			a = dsu->get(a);
			cout << dsu->get_mn(a) + 1 << " " << dsu->get_mx(a) + 1 << " " << dsu->get_sz(a) << "\n";
		}
	}
}

int main(){
	fast;
  int t = 1;
  while(t--){
    run_case();
  }
}