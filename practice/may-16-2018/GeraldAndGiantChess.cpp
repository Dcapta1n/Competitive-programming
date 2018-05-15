/******************
*	Subham kumar  *
*				  *	
*******************/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vi;
#define  F first 
#define  S second
typedef pair<ll,ll> ii;
#define boost ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define pb push_back
#define fl(i,a,b) for(int i=int(a);i<=int(b);i++)
#define mp make_pair
#define all(c) c.begin(),c.end()
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define PI 3.14159265359
#define N 4000000
#define mod 1000000007
ll f[N];
ll ifact[N];
vii v;
ll pow1(ll a,ll b){
	ll ans = 1;
	while(b!=0){
		if(b&1){
			ans = ans *a;
			ans%=mod;
		}
		a = a * a ;
		a %= mod;
		b=b/2;
	}
	return ans%mod;
}
void fact(){
	f[0]=1;
	for(ll i=1;i<N;i++){
		f[i]=f[i-1]*i;
		f[i]%=mod;
	}
	ifact[N-1]=pow1(f[N-1],mod-2);
	for(ll i=N-2;i>=0;i--){
		ifact[i]=ifact[i+1]*(i+1);
		ifact[i]%=mod;
	}

}
ll ncr(ll n,ll r){ 
	if(n<0 or r<0 ){
		return 1;
	}
	ll ans = f[n];
	ans = ans * ifact[r];
	ans%=mod;
	ans = ans * ifact[n-r];
	return ans%mod;
}
ll dp[N];
int main(){
boost;
	ll h,w,n;
	fact();
	cin>>h>>w>>n;
	for(int i=0;i<n;i++){
		ll x,y;

		cin>>x>>y;
		v.pb(mp(x,y));	
	}
	sort(all(v));
	v.pb(mp(h,w));
	for(int i=0;i<v.size();i++){
		ll I = v[i].F,J=v[i].S;
		dp[i]=ncr(I+J-2,I-1);
		dp[i]%=mod;
		//cout<<dp[i]<<endl;
		for(int j=0;j<v.size();j++){
			ll xx = v[j].F,yy=v[j].S;
			if(i==j){continue;}
			ll sub = (dp[j]*ncr(I+J-xx-yy,I-1-xx))%mod;
			if(xx<=I and yy<=J){	
				dp[i]= dp[i] - (dp[j]*ncr(I+J-xx-yy,I-xx))%mod;
			//	cout<<sub<<" ";
			}
			while(dp[i]<0){
				dp[i]+=mod;
			}
		}
	}
	cout << dp[v.size()-1]%mod <<endl;
		
 	



return 0;
}
 	
