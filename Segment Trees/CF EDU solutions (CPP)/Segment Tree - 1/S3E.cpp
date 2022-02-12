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

//Mass update : prefix sum trick
//A mass update of sums can be changed to point update using +x/-x trick of prefix sums.
//Then the value of a particular element is the prefix sum uptil that element.
//Lazy propagation is used to solve more general mass update operations but here we can use this trick on +.
//Lets code it!
//Note sometimes there might be WA verdict if your segment tree has precise nodes as power of 2. Always good to initialize with a small offset.
//Here n+10.

class segtree{
	public:
		vector<ll> T;
		int sz = 1;
		void init(int n){
			while(sz<n)
				sz*=2;
			T.assign(2*sz,0LL);
		}
		void upd(int x,int l,int r,ll val,int pos){
			if(r-l==1){
				T[x]+=val;
				return;
			}
			int m = (l+r)/2;
			if(pos<m)
				upd(2*x+1,l,m,val,pos);
			else
				upd(2*x+2,m,r,val,pos);
			T[x] = T[2*x+1] + T[2*x+2];
		}
		void upd(int val,int pos){
			upd(0,0,sz,val,pos);
		}
		ll calc(int x,int l,int r,int ql,int qr){
			if(l>=qr || r<=ql)
				return 0;
			if(l>=ql && r<=qr)
				return T[x];
			int m = (l+r)/2;
			ll le = calc(2*x+1,l,m,ql,qr);
			ll ri = calc(2*x+2,m,r,ql,qr);
			return le+ri;
		}
		ll calc(int ql,int qr){
			return calc(0,0,sz,ql,qr);
		}
}; 

int main(){
	fast;
	int n,m;
	cin >> n >> m;

	segtree st;
	st.init(n+10);

	rep(i,m){
		int op;
		cin >> op;
		if(op==1){
			int l,r;
			ll v;
			cin >> l >> r >> v;
			st.upd(v,l);
			st.upd(-1LL*v,r);
		}
		else{
			int pos;
			cin >> pos;
			cout<<st.calc(0,pos+1)<<"\n";
		}
	}
}