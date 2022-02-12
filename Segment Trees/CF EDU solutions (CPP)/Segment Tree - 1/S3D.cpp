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

//2 cases:
//yxyx
//xyxy

//Create coordinate pairs.
//Note : Currently we are on <l,r> pair and we are looking at all other visited <xl,xr> pairs.

//Case 1 : yxyx
//Sort pairs in ascending by right endpoint.
//Iterate pairs in forward order.
//xl l xr r
//xl xr l r
//[#xl < l - #xr < l]
//Is sorting really required ?
//No, if we are at some point r that means we have seen the entire line segment <l,r> and it is correct to say that lines having xr > r are yet to be reached.
//i.e. we only add lines once we see their right endpoints
//So just iterating in a forward would suffice.

//Case 2(Mirror Case 1) : xyxy
//Sort pairs in ascending by left endpoint.
//Iterate pairs in reverse order.
//l xl r xr
//l r xl xr
//[#xr > r - #xl > r]
//Is sorting really required ?
//No, if we are at some point l that means we have seen the entire line segment <l,r> and it is correct to say that lines having xl < l are yet to be reached.
//i.e. we only add lines once we see their left endpoints.
//So just iterating in reverse would suffice.

//Each inequality(total 4) in above 2 cases requires a separate segment tree to solve.
//Maybe I broke this down a bit too much creating a very "coding what I see" solution.
//It might also be doable with a single segment tree, have to give it more thought.
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
			if(pos<m)
				upd(2*x+1,l,m,val,pos);
			else
				upd(2*x+2,m,r,val,pos);
			T[x] = T[2*x+1] + T[2*x+2];
		}
		void upd(int val,int pos){
			upd(0,0,sz,val,pos);
		}
		int calc(int x,int l,int r,int ql,int qr){
			if(l>=qr || r<=ql)
				return 0;
			if(l>=ql && r<=qr)
				return T[x];
			int m = (l+r)/2;
			int le = calc(2*x+1,l,m,ql,qr);
			int ri = calc(2*x+2,m,r,ql,qr);
			return le+ri;
		}
		int calc(int ql,int qr){
			return calc(0,0,sz,ql,qr);
		}
};
int main(){
	fast;
	int n;
	cin >> n;

	vector<int> a(2*n);

	rep(i,2*n){
		cin >> a[i];
		--a[i];
	}
	vector<int> ok_f[n];
	vector<int> ok_b[n];

	segtree st_f_l,st_f_r,st_b_r,st_b_l;
	
	st_f_l.init(2*n);
	st_f_r.init(2*n);
	st_b_l.init(2*n);
	st_b_r.init(2*n);
	
	vector<int> ans(n,0);
	
	rep(i,2*n){
		//xl l xr r
		//xl xr l r
		if((int)ok_f[a[i]].size()==1){
			ok_f[a[i]].pb(i);
			int l = ok_f[a[i]][0];
			int r = ok_f[a[i]][1];
			ans[a[i]]+=st_f_l.calc(0,l) - st_f_r.calc(0,l);
			st_f_r.upd(1,r);
			st_f_l.upd(1,l);
		}
		else{
			ok_f[a[i]].pb(i);
		}
	}
	cout<<endl;
	rrep(i,2*n){
		//l xl r xr
		//l r xl xr
		if((int)ok_b[a[i]].size()==1){
			ok_b[a[i]].pb(i);
			int l = ok_b[a[i]][1];
			int r = ok_b[a[i]][0];
			ans[a[i]]+=st_b_r.calc(r+1,2*n) - st_b_l.calc(r+1,2*n);
			st_b_r.upd(1,r);
			st_b_l.upd(1,l);
		}
		else{
			ok_b[a[i]].pb(i);
		}
	}

	rep(i,n)
		cout<<ans[i]<<" ";
}