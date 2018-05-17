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
map<ll,ll> m;
int n;
ll a[N];
int dfs(ll s,ll p){
	ll c1 = s*2;
//	cout<<s<<" "<<p<<endl;

	if(m.find(s)==m.end()){
		if(p>=n){
			return true;
		}
		return false;
	}
	ll c1k = dfs(c1,p+1);
	if(c1k){
		return true;
	}
	if(s%3==0){
		ll c2 = s/3;
		int c2k = dfs(c2,p+1);
		if(c2k){
			return true;
		}
	}
	return false;

}
int dfs1(ll s,int p){
	ll c1 = s*2;
	//cout<<s<<" "<<p<<endl;
	
	if(m.find(s)==m.end() or p>n){
		if(p>=n){
			return true;
		}
		return false;
	}
	cout<<s<<" ";
	ll c1k = dfs1(c1,p+1);
	if(c1k){
		return true;
	}
	if(s%3==0){
		ll c2 = s/3;
		int c2k = dfs1(c2,p+1);
		if(c2k){
			return true;
		}
	}
	return false;
}
int main(){
boost;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m[a[i]]=1;
	}
	ll st = 0;
	for(int i=0;i<n;i++){
		if(dfs(a[i],0)){
			st = a[i];
		}
	}
	dfs1(st,0);
	cout<<endl;
//	cout<<st<<endl;
 	





return 0;
}
 	
