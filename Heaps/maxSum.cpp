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

//link: https://atcoder.jp/contests/abc376/tasks/abc376_e

void run_case() {
	int n,k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	rep(i,n)
		cin >> a[i];
	rep(i,n)
		cin >> b[i];
	
	auto cmp = [&](const int &i, const int &j){
		return a[i]<a[j];
	};

	auto pq_cmp = [](const int &b, const int &a){
		return a>b;
	};

	vector<int> idx(n);
	iota(all(idx), 0);
	sort(all(idx), cmp);
	priority_queue<int, vector<int>, decltype(pq_cmp)> pq(pq_cmp);
	ll sum = 0;
	ll ans = 1e18;
	rep(i,n){
		int id = idx[i];
		if(pq.size()<k-1){
			pq.push(b[id]);
			sum+=b[id];
			continue;
		}
		ans = min(ans, 1LL*a[id]*(1LL*sum + 1LL*b[id]));
		if(pq.size()>0 && pq.top()>b[id]){
			sum-=pq.top();
			sum+=b[id];
			pq.pop();
			pq.push(b[id]);
		}
	}
	cout << ans << '\n';

}
 
int main() {
	fast;
	int t;
	cin >> t;
  while(t--){
    run_case();
  }
}