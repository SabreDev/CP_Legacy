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

//Given number of inversions of every element in the original array, find the original array. 
//Eg : this is given : 0 1 1 0 3
//At the final stage we know that we have seen all elements : 1 1 1 1 1 call this X
//Lets traverse from right to left. In this eg, 3 represents that there is some number which has 3 elements greater then it to the left.
//So our task is to find the the position of the 4th one from the right X as it will have 3 ones to the right of it.
//4th one from the right means (5-4+1)th one from the left.
//We find that the position is 2, and so the last element in the original array must be 2.
//Set that position in x to 0 So now our array x looks like : 1 0 1 1 1. and now we look for the 1st one from right = (4-1+1)th one from left.
//As there are 4 ones remaining we have to consider 4 and not 5 when finding left position. In the next iteration it will be 3 and so on.
//Repeat this process until we get the answer permutation. X will then be 0 0 0 0 0 at the end.
//Similiar to finding the kth one.
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
		//Get kth one from left.
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
	int n;
	cin >> n;
	vector<int> a(n);

	segtree st;
	st.init(n);

	rep(i,n){
		cin >> a[i];
	}
	//Build tree of 1's
	rep(i,n){
		st.upd(1,i);
	}

	vector<int> ans;
	int num_ones = n;
	rrep(i,n){
		int pos = st.calc(num_ones-(a[i]+1)+1);
		ans.pb(pos+1); // position of kth one from left returned will be 0-indexed so add 1 to convert to 1-indexed.
		st.upd(0,pos);
		--num_ones;
	}
	reverse(all(ans));
	for(int x : ans)
		cout<<x<<" ";
}