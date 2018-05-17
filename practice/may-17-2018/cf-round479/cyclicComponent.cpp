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
vi g[N];
int vis[N];
int flag;
void dfs(int s,int p){
	vis[s]=1;
	int f=1;
	for(auto v:g[s]){
		if(v==s){
			flag=-10000000;
		}
		if(v==p){continue;}
		if(vis[v]==0){
			dfs(v,s);
		}else if(vis[v]==1){
			flag++;
		}
		f=0;
	}
	if(f){
		flag=-1000000;
	}
	vis[s]=2;
}


int main(){
boost;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		ll u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);	
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		flag =0 ;
		if(vis[i]==0){
			dfs(i,-1);
		}
		if(flag==1){
			cnt++;
		}
	}
 	
 	cout<<cnt<<endl;



return 0;
}
 	
