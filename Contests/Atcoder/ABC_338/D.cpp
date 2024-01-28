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

void calc(int from, int to, int n, vector<ll> &d){
	if(from <= to){
		d[to]+=(to - from);
		d[1]+=(to-from);
		d[from]-=(to-from);
	} else {
		d[to]+= n - (from - to);
		d[from]-= n - (from - to);
	}
}

void run_case() {
	int n,m;
	cin >> n >> m;
	vector<int> x(m);
	rep(i,m)
		cin >> x[i];

	//Going from x -> y
	//All bridges in between x and y when cut contribute going the other way round to the answer
	//x -> 1 -> y
	//All bridges when cut between the other route of x and y contribute going through x and y to the answer
	//Vx+=1, Vy-=1
	//Min answer is prefix sums of V array.

	vector<ll> d(n+1, 0);
	rep(i,m-1){
		int from  = x[i];
		int to = x[i+1];
		if(from > to)
			swap(from, to);
		calc(from, to, n, d); //go from -> to (cut bridges in other dir)
		calc(to, from, n, d); //go to -> from (cut bridges from (from->to))
	}

	ll mn = 1e18;
	rng(i,1,n+1){
		d[i] = d[i-1] + d[i];
		mn = min(mn, d[i]);
	}
	cout << mn << "\n";
	
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
