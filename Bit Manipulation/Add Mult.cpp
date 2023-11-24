#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0);
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
#define rng(i,a,b) for(int i=a;i<b;i++)
#define ar array

//Keep addiing carry value to xor sum bit by bit.
//Can handle negative as well.
int add(int a, int b){
  while(b){
    int carry = a&b;
    a^=b;
    b = carry << 1;
  }
  return a;
}

//Sum of a shifted by set bits in b.
//When we get a set bit in b we add the already shifted a by the shift amount of the set bit to answer.
//For negative pass modulus of both and determine sign later.
int mult(int a, int b){
  int prod = 0;
  while(b){
    if(b&1){
      prod = add(prod, a);
    }
    a<<=1;
    b>>=1;
  }
  return prod;
}

void run_case() {
  int a,b;
  cin >> a >> b;
  cout << add(a,b) << " " << mult(a,b) << "\n";

}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
	}
}