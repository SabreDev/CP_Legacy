#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll  long long
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define pii pair<int,pi>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define rng(i,a,b) for(int i=a;i<b;i++)
#define ar array

/*
Note : 
Any kind of associative operation is supported in a segment tree.
&,|,^,gcd(recombining not O(1)),multiplication under modulo,matrix mult.
associative ops : (a*b)*c = a*(b*c) order does not matter.
*/
class segtree{
	public:
		vector<pi> T;
		int sz = 1;
		void init(int n){
			while(sz<n)
				sz*=2;
			T.assign(2*sz,{2e9,0});
		}
		pi combine(pi a,pi b){
			if(a.F==b.F)
				return {a.F,a.S + b.S};
			return {min(a.F,b.F),(a.F<b.F ? a.S : b.S)};
		}
		void upd(int x,int l,int r,int val,int pos){
			if(r-l==1){
				T[x] = {val,1};
				return;
			}
			int m = (l+r)/2;
			if(pos < m)
				upd(2*x+1,l,m,val,pos);
			else
				upd(2*x+2,m,r,val,pos);
			T[x] = combine(T[2*x+1],T[2*x+2]);
		}
		void upd(int val,int pos){
			upd(0,0,sz,val,pos);
		}
		pi calc(int x,int l,int r,int ql,int qr){
			if(r <= ql || l >= qr)
				return {2e9,0};
			if(l >= ql && r <= qr)
				return T[x];
			int m = (l+r)/2;
			pi le = calc(2*x+1,l,m,ql,qr);
			pi ri = calc(2*x+2,m,r,ql,qr);
			return combine(le,ri);
		}
		pi calc(int ql,int qr){
			return calc(0,0,sz,ql,qr);
		}
};
int main(){
	fast;
	int n,m;
	cin >> n >> m;

	segtree st;
	st.init(n);

	rep(i,n){
		int x;
		cin >> x;
		st.upd(x,i);
	}
	rep(i,m){
		int op;
		cin >> op;
		if(op==1){
			int pos,val;
			cin >> pos >> val;
			st.upd(val,pos);
		}
		else{
			int l,r;
			cin >> l >> r;
			pi ans = st.calc(l,r);
			cout<<ans.F<<" "<<ans.S<<"\n";
		}
	}
}