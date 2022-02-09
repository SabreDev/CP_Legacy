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

//Kth-one : K is 0 indexed, return answer as 0-indexed. So 0th one means the 1st one (Dumb, yeah ik)
//Store sum of 1's and 0's in nodes of seg tree.
//Say we are at some segment. It is made of 2 child segments; C1,C2
//if C1_sum >= K go to C1.
//else We look for the (K - C1_sum)th one in C2 and goto C2. Our new K = K - C1_sum
//For flipping we can simply xor it with 1.
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
			T[x] = T[2*x+1] + T[2*x+2];
		}
		void upd(int val,int pos){
			upd(0,0,sz,val,pos);
		}
		void flip(int x,int l,int r,int pos){
			if(r-l==1){
				T[x]^=1;
				return;
			}
			int m = (l+r)/2;
			if(pos < m)
				flip(2*x+1,l,m,pos);
			else
				flip(2*x+2,m,r,pos);
			T[x] = T[2*x+1] + T[2*x+2];

		}
		void flip(int pos){
			flip(0,0,sz,pos);
		}
		int calc(int x,int l,int r,int k){
			if(r-l==1){
				return l;
			}
			int m = (l+r)/2;
			if(T[2*x+1]>=k)
				return calc(2*x+1,l,m,k);
			else
				return calc(2*x+2,m,r,k-T[2*x+1]);
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
			int pos;
			cin >> pos;
			st.flip(pos);
		}
		else{
			int k;
			cin >> k;
			cout<<st.calc(k+1)<<"\n";
		} 
	}
}