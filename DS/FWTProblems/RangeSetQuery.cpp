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

//Problem link: https://atcoder.jp/contests/abc174/tasks/abc174_f
//Problem desc: Find count of distinct elements in given ranges.

class FenwickTree {
	vector<int> tree;
	int n;
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
	int n,q;
	cin >> n >> q;
	vector<int> a(n);
	rep(i,n)
		cin >> a[i];
	
	
	vector<vector<pi>> query_bucket(n);
	rep(i,q){
		int l, r;
		cin >> l >> r;
		--l, --r;
		query_bucket[r].pb({l, i});
	}

	unordered_map<int,int> last_seen;
	FenwickTree* BIT = new FenwickTree(n);
	vector<int> ans(q);

	rep(i,n){
		if(last_seen.count(a[i])){
			BIT->update(last_seen[a[i]], -1);
		}
		BIT->update(i, 1);
		last_seen[a[i]] = i;
		for(pi l: query_bucket[i]){
			ans[l.S] = BIT->query(l.F, i);
		}
	}

	for(int x: ans)
		cout << x << "\n";
}
int main(){
	fast;
  int t = 1;
  while(t--){
    run_case();
  }
}