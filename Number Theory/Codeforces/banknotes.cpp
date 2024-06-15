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

//Problem link: https://codeforces.com/problemset/problem/1606/C

long long exp(long long x, long long n) {
	//x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
	long long res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x; }
		x = x * x;
		n /= 2;
	}
	return res;
}

void run_case() {
	ll n,k;
	cin >> n >> k;
	++k;
	vector<int> a(n);
	rep(i,n)
		cin >> a[i];
	if(n==1){
		cout << k * exp(10, a[0]) << '\n';
		return;
	}
	ll ans = 0;
	
	rep(i,n-1){
		if(k==0)
			break;
		
		ll can = 9, t = 10, use, nxt = exp(10, a[i+1]), cur = exp(10, a[i]);
		while(can * cur < nxt){
			use = can;
			can+=9*t;
			t*=10;
		}

		if(k>=use)
			k-=use;
		else{
			use=k;
			k=0;
		}
		ans+=use*cur;
	}
	ans+=k*exp(10, a[n-1]);
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
