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

//Problem link: https://codeforces.com/contest/1838/problem/C

bool p_check(int x){
	for(int i=2;i*i<=x;++i){
		if(x%i==0)
			return false;
	}
	return true;
}

bool check(int x, int i, int j, int n, int m, vector<vector<int>> &g){
	int d1 = abs(g[n-2][m-1]-g[i][j]);
	int d2 = abs(g[n-1][m-2]-g[i][j]);
	int d3 = i+1<n ? abs(g[i+1][j]-x) : 4;
	int d4 = j+1<m ? abs(g[i][j+1]-x) : 4;
	int d5 = i>0 ? abs(g[i-1][j]-x) : 4;
	int d6 = j>0 ? abs(g[i][j-1]-x): 4;

	if(!p_check(d1) && !p_check(d2) && !p_check(d3) && !p_check(d4) && !p_check(d5) && !p_check(d6))
		return true;
	return false;
}

void run_case() {
	int n,m;
	cin >> n >> m;
	bool p = p_check(m);
	if(p){
		vector<vector<int>> g(n, vector<int>(m));
		rep(i,n)
			rep(j,m-1)
				g[i][j] = i*(m-1) + j + 1;
		int x = n*m - 1;
		rep(i,n-1){
			g[i][m-1] = x;
			x--;
		}
		bool ok = false;
		rep(i,n){
			rep(j,m){
				if(check(n*m,i,j,n,m,g)){
					g[n-1][m-1] = g[i][j];
					g[i][j] = n*m;
					ok=true;
					break;
				}
			}
			if(ok)
				break;
		}

		rep(i,n){
			rep(j,m){
				cout << g[i][j] << " ";
			}
			cout << "\n";
		}

	} else {
		rep(i,n){
			rep(j,m){
				cout << i*m + j + 1 << " ";
			}
			cout << "\n";
		}
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
