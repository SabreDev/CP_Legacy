//https://atcoder.jp/contests/abc321/tasks/abc321_f

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

const ll MOD = 998244353;

void run_case(){
  int q,k;
	cin >> q >> k;
	vector<ll> dp(k+1, 0);
	dp[0] = 1;

	rep(i,q){
		char op;
		int b;
		cin >> op >> b;
		if(op=='+'){
			//reversing loop order eliminates need of ndp to not count overwritten states.
			rrep(i,k+1){
				if(i-b>=0)
					(dp[i]+=dp[i-b])%=MOD;
				else
					break;
			}
		} else {
			rep(i,k+1){
				if(i+b<=k)
					dp[i+b] = (dp[i+b] - dp[i] + MOD)%MOD;
				else
					break;
			}
		}		
		cout << dp[k] << "\n";
	}
}

int main(){
	fast;
	int t=1;
	while(t--){
    run_case();
	}
}