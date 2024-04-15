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

//Problem link : https://cses.fi/problemset/task/1645

void run_case() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n)
		cin >> a[i];
	stack<pair<int,int>> st; //elem, idx
	vector<int> ans(n, 0);
	rrep(i,n){
		while(!st.empty() && a[i] < st.top().F){
			ans[st.top().S] = i + 1;
			st.pop();
		}
		st.push(mp(a[i],i));
	}
	for(int x: ans)
		cout << x << " ";
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
