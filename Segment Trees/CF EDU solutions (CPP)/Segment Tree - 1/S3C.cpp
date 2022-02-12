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

//Number of nested segments.
//We can rephrase thiis problem interms of line segmens.
//Convert to coordinates
//Find # of line segments that are completely inside some line segment i for all i
//Procedure is simple
//Make a list of lines (pairs containing coordinates of left and right endpoints).
//Sort the lines in ascending order by their left endpoints.
//Iterate the sorted list in reverse order.(why?)
//As soon as we see a line segment we query for all the right end points 'y' we saw uptil now such that y<x if x is the current right end point of our current line segment.
//Ring any bells ?! Yes we maintain a segment tree for the positions of right endpoints(1 if we saw it else 0) and the above query becomes st.sum(0,y)
//Finally we update the right endpoint that we just saw(x) from 0 to 1 i.e. st.upd(1,x) for future calculations.
//Note here x and y refer to the "positions" of the right endpoints of the line segments.
//By iterating in reverse order we ensure that the left endpoint corresponding to 'y' will always be at a greater position than the left endpoint corresponding to 'x'.
//To add some more closure; our segment tree is finding the number of lines whose right endpoint comes before some given right endpoint while we manually ensure via sorting and iterating in reverse that left endpoints are taken care of.
//Lets code it!

class segtree{	
	public:
		vector<int> T;
		int sz = 1;
		void init(int n){
			while(sz<n)
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
			if(qr<ql)
				return 0;
			return calc(0,0,sz,ql,qr);
		}
};
int main(){
	fast;
	int n;
	cin >> n;
	vector<int> pos[n];
	vector<int> a(2*n);
	vector<int> ans(n);
	rep(i,2*n){
		int x;
		cin >> x;
		--x;
		a[i]=x;
		pos[x].pb(i);
	}
	vector<pi> coor;
	for(auto x : pos){
		coor.pb({x[0],x[1]});
	}
	sort(all(coor));

	segtree st;
	st.init(2*n);
	
	rrep(i,n){
		ans[a[coor[i].F]] = st.calc(0,coor[i].S);
		st.upd(1,coor[i].S);
	}
	rep(i,n)
		cout<<ans[i]<<" ";

}