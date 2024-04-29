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

void run_case() {
	int n,W;
	cin >> n >> W;
	vector<int> v(n), w(n);
	rep(i,n)
		cin >> w[i] >> v[i];
	
	//dp[i] -> min weight required to pick items worth cost i.
	//dp[i] = min(dp[i], dp[i-c[j]]+w[j]); -> not correct as fwd order of loops leads to double counting.
	vector<ll> dp(100010, 2e9);
	dp[0] = 0;

	rep(i,n){
		for(int j=100000;j>=v[i];--j){
			dp[j] = min(dp[j], dp[j-v[i]] + w[i]);
		}
	}

	for(int j=100000;j>=0;--j){
		if(dp[j]<=W){
			cout << j << '\n';
			break;
		}
	}



}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
