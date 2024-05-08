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

//Problem link: https://codeforces.com/problemset/problem/762/A

void run_case() {
	ll n,k;
	cin >> n >> k;
	vector<ll> divs;
	for(ll i=1;i*i<=n;++i){
		if((n%i)==0){
			divs.pb(i);
			if((n/i) != i)
				divs.pb(n/i);
		}
	}
	sort(all(divs));
	if((int)divs.size() >= k)
		cout << divs[k-1];
	else
		cout << -1;

}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
