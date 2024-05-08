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

//Problem link: https://codeforces.com/problemset/problem/1332/B

void run_case() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n){
		cin >> a[i];
	}
	vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31};
	map<int,int> bucket;
	int now = 1;
	vector<int> col(n, -1);
	rep(i,n){
		rep(j,11){
			if((a[i]%primes[j])==0){
				if(bucket[j]==0){
					bucket[j] = now;
					++now;
				}
				col[i] = bucket[j];
				break;
			}
		}
	}
	set<int> h;
	rep(i,n){
		h.insert(col[i]);
	}
	cout << h.size() << "\n";
	for(int x: col)
		cout << x << " ";
	cout << "\n";
	
}
 
int main() {
  fast;
  int t;
	cin >> t;
  while(t--){
    run_case();
  }
}
