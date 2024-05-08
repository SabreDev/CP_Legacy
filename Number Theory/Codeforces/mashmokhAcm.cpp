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

//Problem link: https://codeforces.com/problemset/problem/414/B
ll dp[2005][2005] = {0};
const int mod = 1e9 + 7;

void run_case() {
	int n,l;
	cin >> n >> l;

	rep(i,2005)
		dp[i][1] = 1;
	
	for(int i=1;i<l;++i){
		for(int j=1;j<=n;++j){
			for(int k=j;k<=n;k+=j){
				dp[k][i+1]+=dp[j][i];
				if(dp[k][i+1] >= mod)
					dp[k][i+1]-=mod;
			}
		}
	}

	ll ans = 0;
	rng(i,1,n+1){
		ans+=dp[i][l];
		if(ans >= mod)
			ans-=mod;
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
