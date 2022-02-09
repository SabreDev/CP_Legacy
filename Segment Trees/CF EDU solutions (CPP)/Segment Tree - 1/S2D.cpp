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

//Find minimum index j such that : a[j]>=k and j>=y given <k,y> if such j not exist return -1.
//First element atleast K with a constraint on index. if not exist return -1
//similiar to idea of Kth-one.
//we store max of a segment in our segment tree node.
//Say we are at some segment with child C1,C2 <l,m,r>
//if C1_max >= K and m-1>=y then goto C1. if answer from C1 is -1 then,
//if ans from C1==-1 and C2_max >= K and r-1>=y then goto C2.
//return ans index.
//Implement checking properly.
//Theme of such problems is quite common and the idea is similiar to that of binary search.
//Interestingly, the binary search is being performed on some unsorted random array!
//We are giving it some structure via our segment tree so that we can choose which halves to keep and which to reject 
//ultimately leading us to our answer node just like binary search!
//Lets code it!


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
		int calc(int x,int l,int r,int k,int y){
			if(r-l==1){
				if(T[x]>=k && l>=y)
					return l;
				else
					return -1;
			}
			int m = (l+r)/2;
			int ans=-1;
			if(T[2*x+1]>=k && m-1>=y)
				ans = calc(2*x+1,l,m,k,y);
			if(ans==-1 && T[2*x+2]>=k && r-1>=y)
				ans = calc(2*x+2,m,r,k,y);
			return ans;
		}
		int calc(int k,int y){
			return calc(0,0,sz,k,y);
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
			int k,y;
			cin >> k >> y;
			cout<<st.calc(k,y)<<"\n";
		} 
	}
}