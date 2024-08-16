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

class FenwickTree{
	int n;
	vector<int> tree;
	public:
		FenwickTree(int sz){
			n = sz + 1;
			tree.resize(sz + 1, 0);
		}
		int query(int l, int r){
			return read(r) - read(l - 1);
		}
		int read(int idx){
			++idx;
			int val = 0;
			while(idx > 0){
				val+=tree[idx];
				idx-=(idx&-idx);
			}
			return val;
		}
		void update(int idx, int val){
			++idx;
			while(idx <= n){
				tree[idx]+=val;
				idx+=(idx&-idx);
			}
		}
};
void run_case(){
  int n;
	cin >> n;
	vector<int> a(n);
	FenwickTree* BIT = new FenwickTree(n);
	rep(i,n){
		cin >> a[i];
	}
	unordered_map<int,int> f,pf;
	rrep(i,n){
		++f[a[i]];
		BIT->update(f[a[i]], 1);
	}
	vector<int> ans;
	rep(i,n){
		++pf[a[i]];
		BIT->update(f[a[i]], -1);
		ans.pb(BIT->query(1, pf[a[i]] - 1));
		--f[a[i]];
	}
	ll fans = 0;
	for(int x: ans){
		fans+=1LL*x;
	}
	cout << fans << "\n";
}

int main(){
	fast;
  int t = 1;
  while(t--){
    run_case();
  }
}