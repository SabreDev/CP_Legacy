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

//Problem link: https://codeforces.com/problemset/problem/1312/C


void run_case() {
	ll n,k;
	cin >> n >> k;

	vector<ll> a(n);
	rep(i,n){
		cin >> a[i];
	}

	set<int> uniq_pows;

	rep(i,n){
		ll x = a[i];
		//find in base-k
		int step_cnt = 0;
		while(x > 0){
			ll rem = x % k;
			x/=k;
			if(rem>1){
				cout << "NO" << "\n";
				return;
			}
			if(rem==1){
				if(uniq_pows.count(step_cnt)){
					cout << "NO" << "\n";
					return;
				}
				uniq_pows.insert(step_cnt);
			}
			++step_cnt;
		}
	}
	
	cout << "YES" << "\n";
	
}
 
int main() {
  fast;
  int t;
	cin >> t;
  while(t--){
    run_case();
  }
}
