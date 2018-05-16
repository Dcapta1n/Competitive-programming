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
ll a[N];
vi g[N];
ll dp1[60000][309];
ll dp2[200];
ll k;
ll ans=0;
void dfs(int s,int p){
	dp1[s][a[s]]=1;
	//cout<<s<<" zz "<<p<<endl;
	
	for(auto v : g[s]){
	
		if(v==p){continue;}
		dfs(v,s);
		for(int i=0;i<=k;i++){
			dp2[i]=dp1[s][i];
		}
		for(int i=0;i<=k;i++){
			for(int j=0;j<=k-i;j++){
				dp2[i+j]+= ((dp1[s][i]*dp1[v][j])%mod);
				//cout<<s<<" "<<dp1[s][i]<<" "<<dp1[v][j]<<" "<<dp2[i+j]<<endl;
				dp2[i+j]%=mod;
			}
		}
		for(int i=0;i<=k;i++){
			dp1[s][i]=dp2[i];
	//		cout<<dp1[s][i]<<" ";
		}
	//	cout<<endl;
	}

	ans+=dp1[s][k];
	ans%=mod;
}

int main(){
boost;
	int t;
	cin>>t;
	while(t--){
		ll n;
		memset(dp1,0,sizeof dp1);
		memset(g,0,sizeof g);
		ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n-1;i++){
			ll u,v;
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		
		dfs(1,0);
		
		cout<<ans<<endl;
		


	}
 	



return 0;
}
 	
