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

//https://codeforces.com/contest/977/problem/F
void run_case() {
 int n;
 cin >> n;
 vector<int> a(n);
 rep(i,n){
  cin >> a[i];
 }
 map<int,int> dp;
 rep(i,n){
  dp[a[i]] = max(1, max(dp[a[i]], dp[a[i]-1]+1));
 }
 int ans = 0;
 int mx = -1;
 for(auto [x,y]: dp){
  if(y>ans){
    ans = y;
    mx = x;
  }
 }
 int req = mx;
 vector<int> idx;
 rrep(i,n){
  if(a[i]==req){
    idx.pb(i+1);
    --req;
  }
 }
 reverse(all(idx));
 cout << ans << "\n";
 for(int x: idx)
  cout << x << " ";
cout << "\n";
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}