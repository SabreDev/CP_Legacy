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

//Problem link: https://codeforces.com/problemset/problem/1285/C

void run_case() {
	ll x;
	cin >> x;
	ll tx = x;
	vector<ll> h;
	for(ll i=2;i*i<=x;++i){
		ll now = 1;
		while(x%i==0){
			now*=i;
			x/=i;
		}
		if(now>1)
			h.push_back(now);
	}
	if(x>1)
		h.push_back(x);
	
	int sz = h.size();
	h.resize(sz);
	vector<ll> ans(2);
	ll mn = 1e18;
	for(int i=0;i<(1<<sz);++i){
		ll f = 1;
		for(int j=0;j<sz;++j){
			if(i&(1<<j))
				f*=h[j];
		}
		ll s = tx / f;
		if(max(f,s) < mn){
			mn = max(f,s);
			ans[0] = f;
			ans[1] = s;
		}
	}
	cout << ans[0] << " " << ans[1] << "\n";

}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
