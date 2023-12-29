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
#define rng(i,a,b) for(int i=a;i<b;i++)
#define ar array

const int MOD = 1e9 + 7;

void run_case(){
  int n,x;
  cin >> n >> x;
	vector<int> c(n);
	rep(i,n)
		cin >> c[i];

	vector<ll> dp(x+1, 0);
	dp[0] = 1;
	
	//We have sum = x, we can make sum = x + coin[i] from x in dp[x] ways.
	//We only use a certain coin once to reach all states it can touch.
	rep(i,n){
		rep(j,x+1){
			if(j+c[i]<=x)
				(dp[j+c[i]]+=dp[j])%=MOD;
		}
	}
	cout << dp[x] << "\n";

}

int main(){
	fast;
	int t=1;
	while(t--){
    run_case();
	}
}