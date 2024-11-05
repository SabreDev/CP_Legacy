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

void run_case() {
	int n,q;
	cin >> n >> q;
	vector<int> a(n);
	vector<ll> p(n);
	rng(i,1,n+1){
		cin >> a[i];
		p[i]=p[i-1]+a[i];
	}
	while(q--){
		
	}
}
 
int main() {
  fast;
  int t;
		cin >> t;
  while(t--){
    run_case();
  }
}
