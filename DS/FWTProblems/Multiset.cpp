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

const int SZ = 1000010;
int tree[1000010];

int read(int idx){
	int val=0;
	while(idx > 0){
		val+=tree[idx];
		idx-=(idx&-idx);
	}
	return val;
}
int query(int l, int r){
	return read(r) - read(l-1);
}
void update(int idx, int val){
	while(idx <= SZ){
		tree[idx]+=val;
		idx+=(idx&-idx);
	}
}

void run_case() {
	int n,q;
	cin >> n >> q;

	rep(i,n){
		int x;
		cin >> x;
		update(x, 1);
	}

	while(q--){
		int k;
		cin >> k;
		if(k>0){
			update(k, 1);
		} else {
			k*=-1;
			int l=1, r=n;
			int e=-1;
			while(l<=r){
				int m = (l+r)/2;
				int cum_sum = read(m);
				if(cum_sum >= k){
					r=m-1;
					e=m;
				} else {
					l=m+1;
				}
			}
			update(e, -1);
		}
	}
	if(read(n)==0){
		cout << 0;
		return;
	}
	int k=1;
	int l=1, r=n;
	int e=-1;
	while(l<=r){
		int m = (l+r)/2;
		int cum_sum = read(m);
		if(cum_sum >= k){
			r=m-1;
			e=m;
		} else {
			l=m+1;
		}
	}
	cout << e;
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
