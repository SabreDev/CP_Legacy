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

//First element atleast K. if not exist return -1
//similiar to idea of Kth-one.
//we store max of a segment in our segment tree node.
//Say we are at some segment with child C1,C2
//if C1_max >= K then goto C1.
//else if C2_max >= K then goto C2.
//else return -1.
//Implement checking properly.
//Lets code it.

class segtree{
	public:
		vector<int> T;
		int sz = 1;
		void init(int n){
			while(sz < n)
				sz*=2;
			T.assign(2*sz,0);
		}
		void upd(int x,int l,int r,int val,int pos){
			if(r-l==1){
				T[x]=val;
				return;
			}
			int m = (l+r)/2;
			if(pos < m)
				upd(2*x+1,l,m,val,pos);
			else
				upd(2*x+2,m,r,val,pos);
			T[x] = max(T[2*x+1],T[2*x+2]);
		}
		void upd(int val,int pos){
			upd(0,0,sz,val,pos);
		}
		int calc(int x,int l,int r,int k){
			if(r-l==1){
				if(T[x]>=k)
					return l;
				else
					return -1;
			}
			int m = (l+r)/2;
			if(T[2*x+1]>=k)
				return calc(2*x+1,l,m,k);
			else if(T[2*x+2]>=k)
				return calc(2*x+2,m,r,k);
			else
				return -1;
		}
		int calc(int k){
			return calc(0,0,sz,k);
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
			int k;
			cin >> k;
			cout<<st.calc(k)<<"\n";
		} 
	}
}