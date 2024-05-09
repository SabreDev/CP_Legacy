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

//Problem link: https://codeforces.com/contest/1714/problem/E

void run_case() {
	int n;
	cin >> n;
	vector<int> a(n);
	set<int> digs;
	bool ok = true;
	int prev = -1;
	rep(i,n){
		cin >> a[i];
		if(prev!=-1 && a[i]!=prev)
			ok = false;
		prev = a[i];
		digs.insert(a[i]%10);
	}
	vector<int> ev = {2,4,6,8};

	if(digs.count(5) || digs.count(0)){
		for(int x: ev){
			if(digs.count(x)){
				cout << "No" << "\n";
				return;
			}
		}
		set<int> h;
		rep(i,n){
			if((a[i]%10)==5){
				h.insert(a[i] + 5);
			} else {
				h.insert(a[i]);
			}
		}
		if(h.size()==1){
			cout << "Yes";
		} else {
			cout << "No";
		}
		cout << "\n";
		return;
	}

	if(ok){
		cout << "Yes" << '\n';
		return;
	}

	rep(i,n){
		if(find(all(ev), a[i]%10) != ev.end())
			continue;
		a[i] = a[i] + a[i]%10;
	}

	int mx = *max_element(all(a));

	rep(i,n){
		int now = a[i] + 20 * ((mx - a[i]) / 20);
		bool match = false;
		while(now <= mx){
			if(now == mx){
				match = true;
				break;
			}
			now = now + now%10;
		}
		if(!match){
			cout << "No" << '\n';
			return;
		}
	}
	cout << "Yes" << "\n";
}
 
int main() {
  fast;
  int t;
	cin >> t;
  while(t--){
    run_case();
  }
}
