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

 long long exp(long long x, long long n, long long m) {
		x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
		long long res = 1;
		while (n > 0) {
				if (n % 2 == 1) { res = res * x % m; }
				x = x * x % m;
				n /= 2;
		}
		return res;
}

int main(){
    string s;
    cin >> s;
		int n = s.length();
		vector<long long> hs(n),p_inv(n);
		
		long long mod = 1e9 + 7;
		long long p = 31;
		long long p_pow = 1;

		for(int i=0;i<n;i++){
				(hs[i] = (i>0?hs[i-1]:0) + (int)(s[i]-'a')*p_pow)%mod;
				p_pow = (p_pow*p)%mod;
		}

		p_inv[0] = 1;
		p_inv[1] = exp(p, mod - 2, mod);
		for(int i=2;i<n;++i){
				p_inv[i] = (p_inv[i-1]*p_inv[1])%mod;
		}

    auto get_substring_hash = [&](const int &l, const int &r, vector<long long> &h) -> long long{
				if(l>r)
						return mod;
				return (((h[r] - (l>0 ? h[l-1] : 0) + mod)%mod)*p_inv[l])%mod;
		};

		cout << get_substring_hash(2, 4, hs) << endl;
}