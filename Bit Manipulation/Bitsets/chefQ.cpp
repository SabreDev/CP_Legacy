#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define pii pair<int,pi>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define cusrep(i,a,b,j) for(int i=a;i<b;i+=j)
#define rng(i,a,b) for(int i=a;i<b;i++)
#define rrng(i,a,b) for(int i=a;i>b;--i)
#define ar array

//Problem link: https://www.codechef.com/problems/CHEFQUE

const long long sz = 1LL<<32;

bitset<sz> x;
//Memory complexity: O((A/W)*(W/8))
//Time complexity to do bitwise ops: O((A/W))

void run_case() {
    ll q,s,a,b;
	cin >> q >> s >> a >> b;
	
	ll ans = 0;
	ll now =  s;
	while(q--){
		if(now%2==0){
		  ll xx = now/2;
			if(x[xx]==1){
				ans-=xx;
			    x[xx] = 0;
			}
		} else {
		    ll xx = now/2;
			if(x[xx]==0){
				ans+=xx;
			    x[xx] = 1;
			}
		}
		now = ((a*now)%sz + b)%sz;
	}
	cout << ans << "\n";

}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
