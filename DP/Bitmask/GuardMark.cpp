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

//https://usaco.org/index.php?page=viewproblem2&cpid=494

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

void run_case() {
	ll n,h;
	cin >> n >> h;
	vector<vector<ll>> a(n, vector<ll>(3));
	rep(i,n){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	vector<ll> dp(1<<n, -1e15);
	rep(i,n){
		dp[1<<i] = a[i][2];
	}
	rng(mask,1,1<<n){
		rep(i,n){
			if(mask&(1<<i)){
				if(dp[mask^(1<<i)]>=a[i][1]){
						dp[mask] = max(dp[mask], min(dp[mask^(1<<i)] - a[i][1], a[i][2]));
				}
			}
		}
	}
	ll ans = -1;
	rep(mask,1<<n){
		ll tot_h=0;
		rep(i,n){
			if(mask&(1<<i)){
				tot_h+=a[i][0];
			}
		}
		if(tot_h>=h){
			rep(i,n){
				if(mask&(1<<i)){
					if(dp[mask]>=0)
						ans=max(ans, dp[mask]);
				}
			}
		}
	}
	if(ans==-1){
		cout << "Mark is too tall";
		return;
	}
	cout << ans;
}
 
int main() {
  //fast;
	setIO("guard");
  int t=1;
  while(t--){
    run_case();
  }
}
