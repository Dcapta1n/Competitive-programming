/******************
*	Subham kumar  *
*				  *	
*******************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned ll
#define vi vector<ll>
#define  F first 
#define  S second
#define ii pair<ll,ll>
#define boost ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define pb push_back
#define mp make_pair
#define all(c) c.begin(),c.end()
#define PI 3.14159265359
#define N 4000000
#define mod 1000000007
#define vii vector<ii> 
#define debug1 cout<<"debug1"<<endl;
#define debug(x) cout<<"this is "<<x<<endl;
/***************************************************************/
#define red 1
#define blue 2
#define green 3
int n,rb,rg,bg,br,gr,gb;
ll f[N];
ll ifact[N];
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
	if(n<r){
		return 0;
	}
	if(r==0){
		return 1;
	}
	if(n==0){
		return 0;
	}
	
	ll ans = f[n];
	ans = ans * ifact[r];
	ans%=mod;
	ans = ans * ifact[n-r];
	return ans%mod;
}
ll dp[4][11][11][11][11][11][11];
ll doit(ll prev,ll a,ll b,ll c,ll d,ll e,ll f){
	if(dp[prev][a][b][c][d][e][f]!=-1){
		return dp[prev][a][b][c][d][e][f];
	}

	ll len = a+b+c+d+e+f+1;
	ll ans =ncr(n-1,len-1);
	//cout<<"here"<<endl;
	if(len==n){
		return ans;
	}
	//cout<<ans<<" "<<prev<<" "<<n<<" "<<len<<endl;
	
	if(prev==red){
		if(a<rb){
			ans += doit(blue,a+1,b,c,d,e,f);
			ans%=mod;
		}
		if(b<rg){
			ans+=doit(green,a,b+1,c,d,e,f);
			ans%=mod;
		}
	}
	else if(prev == blue){
		if(c<br){
			ans+= doit(red,a,b,c+1,d,e,f);
			ans%=mod;
		}
		if(d<bg){
			ans+=doit(green,a,b,c,d+1,e,f);
			ans%=mod;
		}
	}else if( prev == green){
		if(e<gr){
			ans+= doit(red,a,b,c,d,e+1,f);
			ans%=mod;
		}
		if(f<gb){
			ans+=doit(blue,a,b,c,d,e,f+1);
			ans%=mod;
		}
	}


	return dp[prev][a][b][c][d][e][f]=ans%mod;
}

int main(){
boost;
		fact();
		memset(dp,-1,sizeof dp);
		cin>>n>>rb>>rg>>br>>bg>>gr>>gb;
 		ll ans =0 ;
 		for(int i=1;i<=3;i++){
 			ans+= doit(i,0,0,0,0,0,0);
 			ans%=mod;
 		}
 		cout<< ans%mod <<endl;



return 0;
}
 	
