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

//An index i in the Fenwick Tree covers indices from i - (i & -i) + 1 to i.
class FenwickTree {
    vector<int> tree;
    int n;
		public:
			FenwickTree(int sz) {
				n = sz + 1;
				tree.resize(sz + 1, 0);
			}
			int query(int l, int r){
				return read(r) - read(l-1);
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
				while(idx < n){
					tree[idx]+=val;
					idx+=(idx&-idx);
				}
			}
};

void run_case(){
	int n;
	cin >> n;
	vector<int> a(n);
	FenwickTree* fw = new FenwickTree(n);

	rep(i, n){
		cin >> a[i];
		fw->update(i, a[i]);
	}

	int q;
	cin >> q;
	while(q--){
		int id, val;
		cin >> id >> val;
		fw->update(id, val);
		cout << fw->query(0, n-1) << endl;
	}

}
int main(){
	fast;
  int t = 1;
  while(t--){
    run_case();
  }
}