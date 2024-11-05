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

//https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C

class DSU{
	public:
		int n;
		vector<int> p, exp, sz;
		DSU(int num){
			n = num;
			p.resize(num);
			exp.resize(num,0);
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
				exp[a]-=exp[b];
			}
		}
		void upd_exp(int a, int v){
			a = get(a);
			exp[a]+=v;
		}
		int get_exp(int a){
			int ans = 0;
			while(a!=p[a]){
				ans+=exp[a];
				a = p[a];
			}
			ans+=exp[a];
			return ans;
		}
};

void run_case(){
	int n,m;
	cin >> n >> m;
	DSU* dsu = new DSU(n);
	
	while(m--){
		string type;
		cin >> type;
		if(type=="join"){
			int x,y;
			cin >> x >> y;
			--x, --y;
			dsu->unite(x,y);
		} else if(type=="add"){
			int x,v;
			cin >> x >> v;
			--x;
			dsu->upd_exp(x,v);
		} else {
			int x;
			cin >> x;
			--x;
			cout << dsu->get_exp(x) << "\n";
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