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

//Problem link: https://codeforces.com/problemset/problem/474/D

const int MX = 1e5 + 1;
const int mod = 1e9 + 7;
 
int main() {
  fast;
  int t,k;
  cin >> t >> k;
	vector<int> dp(MX,0);
	dp[0] = 1;
	rng(i,1,MX){
		dp[i] = (dp[i-1] + (i>=k?dp[i-k]:0))%mod;
	}
	rng(i,1,MX){
		dp[i] = (dp[i-1] + dp[i])%mod;
	}
  while(t--){
    int a,b;
		cin >> a >> b;
		cout << (dp[b] - dp[a-1] + mod)%mod << "\n";
  }
}
