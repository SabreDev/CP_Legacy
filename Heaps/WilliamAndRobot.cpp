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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n)
		cin >> a[i];
	auto cmp = [](const int&b, const int &a){
		return a<b;
	};
	priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
	for(int i=0;i<n;i+=2){
		if(pq.empty()){
			pq.push(max(a[i], a[i+1]));
			continue;
		}
		if(min(a[i], a[i+1]) > pq.top()){
			pq.pop();
			pq.push(a[i]);
			pq.push(a[i+1]);
		} else {
			pq.push(max(a[i], a[i+1]));
		}
	}
	ll ans = 0;
	while(!pq.empty()){
		ans+=pq.top();
		pq.pop();
	}
	cout << ans << '\n';
}
 
int main() {
	fast;
	int t=1;
	while(t--){
		run_case();
	}
}
