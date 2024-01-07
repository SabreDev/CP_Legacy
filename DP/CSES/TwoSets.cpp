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

const ll MOD = 1e9 + 7;
ll binpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b&1){
			res = res * a % MOD;
		}
		b>>=1;
		a = a * a % MOD;
	}
	return res;
}

void run_case(){
  int n;
  cin >> n;

	int MAX_S = (n*(n+1))/2;

	ll dp[MAX_S + 1];
	rep(i, MAX_S + 1)
		dp[i]=0;

	dp[0]=1;

	rng(i,1,n+1){
		for(int j=MAX_S; j>=i; --j){
			(dp[j]+=dp[j-i])%=MOD;
		}
	}
	cout << (MAX_S%2 ? 0 : (dp[MAX_S/2]*binpow(2, MOD - 2))%MOD) << "\n";

}

int main(){
	fast;
	int t=1;
	while(t--){
    run_case();
	}
}