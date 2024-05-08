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

//Problem link: https://codeforces.com/problemset/problem/235/A

ll gcd(ll a, ll b){
	if(a==0)
		return b;
	return gcd(b % a, a);
}

ll lcm(ll a, ll b){
	return (a * b) / gcd(a, b);
}
void run_case() {
	ll n;
	cin >> n;
	if(n==1){
		cout << 1 << "\n";
		return;
	}
	ll x = 1LL * n * (n-1);
	ll ans = x;
	rng(i,1,n-1){
		ans = max(ans, lcm(i,x));
	}
	ll ans1 = 1LL * (n-1) * (n-2);
	x = ans1;
	rng(i,1,n-2){
		ans1 = max(ans1, lcm(i,x));
	}
	
	cout << max(ans1, ans) << "\n";
	
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
