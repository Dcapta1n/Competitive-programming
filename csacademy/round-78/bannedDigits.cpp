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
vi v;
ll dp[100][100][2];
ll a[10];
ll doit(ll idx,ll tight,ll f){
	if(idx==-1){
		return tight!=1;
	}
	ll ret =0;
	if(dp[idx][tight][f]!=-1){
		return dp[idx][tight][f];
	}

	ll k = (tight)?v[idx]:9;
	
	for(int i=0;i<=k;i++){
		int newTight = v[idx]==i?tight:0;
		if(a[i]){
		    
			if(i==0 and idx!=0 and f){
					ret+=doit(idx-1,newTight,f);
			}

			continue;}

		
		ret+=doit(idx-1,newTight,0);
	}

	return dp[idx][tight][f]=ret;
}
int main(){
boost;
	
	memset(dp,-1,sizeof dp);
	for(int i=0;i<10;i++){
		cin>>a[i];
	}

	ll n;
	cin>>n;
	
	ll y= n;
	ll f=1;
	
	while(y){
		v.pb(y%10);
		if(a[y%10]){
			f=0;
		}
		y=y/10;
	}

		cout<<doit(v.size()-1,1,1)<<endl;


return 0;
}
 	
