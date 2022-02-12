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

//For each i find j < i such that pj > pi where p is a permutation of length n
//Inversions
//Can do using PBDS; fairly short code
//Here we do using segment tree.
//Traverse p from left to right.
//As soon as we see some element we update its value p[i] from 0 to 1 in O(logn)
//Total inversions for that element = sum[p[i]+1,n]; a normal sum query in O(logn)
//Eg we are at p[i] = 5. then do : st.upd(1,5)[<val,pos>] and then st.calc(6,n+1) (sum of [l,r-1]).
//Notice that we donot use 'i' anywhere in our updates and queries but it still plays an important role.
//This 'i' represents the manner in which we traverse the permutation that makes all the difference and gives correct answer in the first place.
//For ease of indexing I convert it to 0-based.
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
				T[x]=1;
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
			return le + ri;
		}
		int calc(int ql,int qr){
			return calc(0,0,sz,ql,qr);
		}
};

int main(){
	fast;
	int n;
	cin >> n;

	vector<int> a(n);

	rep(i,n){
		cin >> a[i];
		--a[i];
	}

	segtree st;
	st.init(n);

	rep(i,n){
		st.upd(1,a[i]);
		cout<<st.calc(a[i]+1,n)<<" ";
	}

}