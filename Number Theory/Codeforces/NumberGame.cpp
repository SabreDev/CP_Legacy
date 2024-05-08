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

//Problem link: https://codeforces.com/problemset/problem/1370/C

void run_case() {
	int n;
	cin >> n;
	int t = n;
	int p2=0;
	while(t%2==0){
		t/=2;
		++p2;
	}
	bool ok = true;
	for(int i=3;i*i<=t;i+=2){
		if(t%i==0){
			ok=false;
			break;
		}
	}
	if(p2==0){
		if(n==1)
			cout << "FastestFinger";
		else
			cout << "Ashishgup";
	}
 	else if(p2>1){
		if(t==1)
			cout << "FastestFinger";
		else
			cout << "Ashishgup";
	}
	else {
		if(t==1)
			cout << "Ashishgup";
		else if(ok)
			cout << "FastestFinger";
		else
			cout << "Ashishgup";
	}
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
