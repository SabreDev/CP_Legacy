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

//https://codeforces.com/gym/102951/problem/C
class FenwickTree{
  int n;
  vector<int> tree;
  public:
    FenwickTree(int sz){
      n = sz + 1;
      tree.resize(n, 0);
    }
    int read(int idx){
      ++idx;
      int val = 0;
      while(idx>0){
        val = max(val, tree[idx]);
        idx-=(idx&-idx);
      }
      return val;
    }
    void update(int idx, int val){
      ++idx;
      while(idx<=n){
        tree[idx]=max(tree[idx], val);
        idx+=(idx&-idx);
      }
    }
};
void run_case() {
 int n;
 cin >> n;
 vector<int> a(n), b(n), idx(n), c(n);
 rep(i,n){
  cin >> a[i];
  --a[i];
  idx[a[i]] = i;
 }
 rep(i,n){
  cin >> b[i];
  --b[i];
  c[i] = idx[b[i]];
 }

 //LIS on C
 FenwickTree* BIT = new FenwickTree(n);
 rep(i,n){
  int now = BIT->read(c[i]-1);
  BIT->update(c[i], now+1);
 }
 int ans = 1;
 rep(i,n){
  ans = max(ans, BIT->read(c[i]));
 }
 cout << ans << "\n";
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
