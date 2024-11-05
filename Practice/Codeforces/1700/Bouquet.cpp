#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi pair<ll,ll>
#define pii pair<int,pi>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define cusrep(i,a,b,j) for(int i=a;i<b;i+=j)
#define rng(i,a,b) for(int i=a;i<b;i++)
#define rrng(i,a,b) for(int i=a;i>b;--i)
#define ar array

//Problem link: https://codeforces.com/problemset/problem/1995/B2

void run_case(){
	ll n,m;
	cin >> n >> m;
	vector<pi> a(n);
	rep(i,n)
		cin >> a[i].F;
	rep(i,n)
		cin >> a[i].S;
	sort(all(a));
	ll ans = 0;
	rep(i,n){
		ll _m = min(m/a[i].F, a[i].S);
		ans = max(ans, a[i].F*_m);
	}	
	rep(i,n-1){
		if(a[i].F+1!=a[i+1].F)
			continue;
		//Buy as many a[i] flowers
		ll _m = m;
		ll q1 = min(_m/a[i].F, a[i].S);
		_m-=q1*a[i].F;
		//Buy as many a[i+1] flowers
		ll q2 = min(_m/a[i+1].F, a[i+1].S);
		ll x = q1*a[i].F + q2*a[i+1].F;
		//Swap as many a[i] flowers as we can with a[i+1] flowers.
		ll poss_swap = min({q1, a[i+1].S - q2, m - x});
		ans = max(ans, x + poss_swap);
	}
	cout << ans << "\n";
}
 
int main() {
  fast;
  int t;
	cin >> t;
  while(t--){
    run_case();
  }
}
