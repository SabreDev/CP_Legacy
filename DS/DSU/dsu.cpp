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

//link: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A

class DSU {
	public:
		int n;
		vector<int> p, sz;
		DSU(int num){
			n = num;
			p.resize(num);
			sz.resize(num, 1);
			rep(i,n)
				p[i] = i;
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
			}
		}
		//works in log time because max rank of a component is log2(size of the component)
		bool check(int a, int b){
			a = get(a);
			b = get(b);
			return a==b;
		}
};
void run_case(){
	int n,m;
	cin >> n >> m;
	DSU* dsu = new DSU(n);
	string type;
	int a,b;
	while(m--){
		cin >> type >> a >> b;
		--a, --b;
		if(type=="union"){
			dsu->unite(a,b);
		} else {
			cout << (dsu->check(a,b)?"YES":"NO") << "\n";
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