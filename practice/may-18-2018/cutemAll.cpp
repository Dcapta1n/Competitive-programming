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

vi g[N],g1[N];
ll dp[N];
ll dp2[N];
int cnt;
int flag;
set<ii> s1;
vii v;

void dfs(int s,int p,int ss){
	dp2[s]=ss+1;
	
	for(auto v:g[s]){
		if(v==p){continue;}
		dfs(v,s,ss+1);
		dp[s]+=dp[v];
	
	}

	
	dp[s]++;
	if(dp[s]%2==0){
		s1.insert(mp(s,p));
		s1.insert(mp(p,s));
		cnt++;
	}
	dp[s]%=2;
	

	
}
int zz ;
int vis[N];
void dfs1(int s,int p){
	zz++;
	vis[s]=1;
	for(auto v:g1[s]){
		if(v!=p){
		dfs1(v,s);
		}
	}
}

int main(){
boost;
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		ll u,v1;
		cin>>u>>v1;
		g[u].pb(v1);
		v.pb(mp(u,v1));
		g[v1].pb(u);
	}
 	dfs(1,0,0);
 	for(int i=0;i<v.size();i++){
 		if(s1.find(v[i])!=s1.end()){continue;}
 		g1[v[i].F].pb(v[i].S);
 		g1[v[i].S].pb(v[i].F);
 	}
 
 	for(int i=1;i<=n;i++){
 		if(vis[i]==0){
 			zz=0;
 			dfs1(i,0);
 			if(zz%2){
 				flag=1;	
 			}
 		}
 	}
 	if(flag){
		cout<<-1<<endl;
 	}else{
 		cout<<cnt-1<<endl;
 	}	



return 0;
}
 	
