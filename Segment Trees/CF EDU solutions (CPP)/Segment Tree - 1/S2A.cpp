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

//we have 2 adjacent segments A and B
//To combine them A + B = C
//C_ans = max(A_ans,B_ans)
//also we have to consider max sum of both when combined which is max suffix sum of segment A and max prefix sum of segment B.
//So C_ans = max(C_ans,A_suff+B_pref)
//where A_suff and B_pref are maximum suffix and prefix sums of segments A and B respectively.
//So we require max pref and suff parameters too.
//We can calculate C_pref =  max(A_pref,A_sum + B_pref) consider max of 2 cases : only A for prefix; consider entire A and B_pref for prefix.
//also C_suff = max(B_suff,B_sum + A_suff) similiar logic as C_pref
//We also require sum parameter in our tree node.
//Sum parameter can be calculated normally by segment tree as we did before.
//So for a particular segment we need 4 parameters : C_pref,C_suff,C_sum,C_ans. All of which can be calculated by equations laid above from its child segments.
//Lets code it!

class Node{
	public:
		ll max_pref,max_suff,sum,ans;
		Node(){

		}
		Node(ll max_pref,ll max_suff,ll sum,ll ans){
			this->max_pref = max_pref;
			this->max_suff = max_suff;
			this->sum = sum;
			this->ans = ans;
		}
};
class segtree{
	public:
		vector<Node> T;
		int sz = 1;
		void init(int n){
			while(sz < n)
				sz*=2;
			T.assign(2*sz,Node(0,0,0,0));
		}
		Node combine(Node A,Node B){
			Node C;
			C.sum = A.sum + B.sum;
			C.max_pref = max(A.max_pref,A.sum + B.max_pref);
			C.max_suff = max(B.max_suff,B.sum + A.max_suff);
			C.ans = max({A.ans,B.ans,A.max_suff + B.max_pref});
			return C;
		}
		void upd(int x,int l,int r,int val,int pos){
			if(r-l==1){
				T[x] = Node(max(val,0),max(val,0),val,max(val,0));
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
		Node calc(int x,int l,int r,int ql,int qr){
			if(l>=qr || r<=ql)
				return Node(0,0,0,0);
			if(l>=ql && r<=qr)
				return T[x];
			int m = (l+r)/2;
			Node le = calc(2*x+1,l,m,ql,qr);
			Node ri = calc(2*x+2,m,r,ql,qr);
			return combine(le,ri);
		}
		Node calc(int ql,int qr){
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
	Node ans = st.calc(0,n);
	cout<<ans.ans<<"\n";
	rep(i,m){
		int pos,val;
		cin >> pos >> val;
		st.upd(val,pos);
		ans = st.calc(0,n);
		cout<<ans.ans<<"\n";
	}
}